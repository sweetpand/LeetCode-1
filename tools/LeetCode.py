from helper import *
from config import *
from tags import *
from threading import Thread
from requests_toolbelt import MultipartEncoder

import sys
import os
import re
import json
import requests
import argparse
import time

# Google Sheets API
import gspread
from oauth2client.service_account import ServiceAccountCredentials
from pprint import pprint


class LeetCode():
    def __init__(self):
        self.session = requests.Session()
        self.session.cookies['LEETCODE_SESSION'] = LEETCODE_SESSION

    def get_percentage(self, API_URL: str):
        headers = {'User-Agent': user_agent, 'Connection': 'keep-alive'}
        res = self.session.get(API_URL, headers=headers, timeout=10)
        res = json.loads(res.content.decode('utf-8'))

        return res['num_solved'], res['num_total'], res['ac_easy'], res['ac_medium'], res['ac_hard']

    def get_problems(self, API_URL: str) -> [dict, list]:
        headers = {'User-Agent': user_agent, 'Connection': 'keep-alive'}
        res = self.session.get(API_URL, headers=headers, timeout=10)
        res = json.loads(res.content.decode('utf-8'))

        return res['stat_status_pairs']

    def get_submissionStatus(self, questionSlug: str) -> dict:
        params = {
            'operationName': 'Submissions',
            'variables': {
                'offset': 0,
                'limit': 20,
                'lastKey': '',
                'questionSlug': questionSlug
            },
            'query':
            """
            query Submissions($offset: Int!, $limit: Int!, $lastKey: String, $questionSlug: String!) {
                submissionList(offset: $offset, limit: $limit, lastKey: $lastKey, questionSlug: $questionSlug) {
                    lastKey
                    hasNext
                    submissions {
                        id
                        statusDisplay
                        lang
                        runtime
                        timestamp
                        url
                        isPending
                        memory
                        __typename
                    }
                    __typename
                }
            }
            """
        }

        jsonData = json.dumps(params).encode('utf8')
        headers = {'User-Agent': user_agent, 'Connection': 'keep-alive', 'Referer': LOGIN_URL,
                   'Content-Type': 'application/json'}
        res = self.session.post(GRAPHQL_URL, data=jsonData,
                                headers=headers, timeout=10)
        content = res.json()

        submissions = {}
        for submission in content['data']['submissionList']['submissions']:
            if submission['statusDisplay'] == 'Accepted' and \
                    submission['lang'] not in submissions.keys() and \
                    submission['lang'] in langs.keys():
                submissions[submission['lang']] = submission

        return submissions

    def getCodeByID(self, submissionID: str) -> str:
        headers = {'User-Agent': user_agent, 'Connection': 'keep-alive',
                   'Content-Type': 'application/json'}
        codeContent = self.session.get(DETAIL_URL + submissionID,
                                       headers=headers,
                                       timeout=1000)
        pattern = re.compile(
            r'submissionCode: \'(?P<code>.*)\',\n  editCodeUrl',
            re.S)

        m1 = pattern.search(codeContent.text)
        code = m1.groupdict()['code'] if m1 else "Error"
        code = code.encode('utf8').decode('unicode_escape')

        return code

    def write_readme(self, problems: list, should_write_solutions: bool):
        # Create 'solutions' directory if needed
        if should_write_solutions:
            if not os.path.exists('solutions'):
                os.makedirs('solutions')

            # Create 'solutions/{lang}' directory if needed
            for lang in langs.keys():
                if not os.path.exists('solutions/' + lang):
                    os.makedirs('solutions/' + lang)

        readme = open('../README.md', 'w')
        try:
            with open('PREFIX.md') as f:
                for line in f:
                    readme.write(line)
        except FileNotFoundError:
            print("No such file or directory: 'PREFIX.md'")

        num_solved, num_total, ac_easy, ac_medium, ac_hard = \
            self.get_percentage(API_URL)

        solved_percentage = round((num_solved / num_total) * 100, 2)
        solved_badge = BADGE_PREFIX + '{0}/{1}%20=%20{2}%25%20Solved-blue'.format(
            num_solved, num_total, solved_percentage) + BADGE_SUFFIX
        easy_badge = BADGE_PREFIX + \
            'Easy%20{0}-5CB85D'.format(ac_easy) + BADGE_SUFFIX
        medium_badge = BADGE_PREFIX + \
            'Medium%20{0}-F0AE4E'.format(ac_medium) + BADGE_SUFFIX
        hard_badge = BADGE_PREFIX + \
            'Hard%20{0}-D95450'.format(ac_hard) + BADGE_SUFFIX
        badges = '\n'.join(
            [solved_badge, easy_badge, medium_badge, hard_badge])

        readme.write('\n## Problem Sets\n\n')
        readme.write('<p align="center">\n')
        readme.write(badges)
        readme.write('\n</p>\n\n')
        readme.write('|#|Title|Solution|Difficulty|\n')
        readme.write('|:--:|:--|:--:|:--:|\n')

        for problem in problems:
            problemID = str(problem['stat']['frontend_question_id']).zfill(4)

            print('Write README.md: ' + problemID)
            readme.write('|' + problemID + '|')
            readme.write('[' + problem['stat']['question__title'] +
                         '](https://leetcode.com/problems/' + problem['stat']['question__title_slug'] + ')')
            readme.write(' 🔒|' if problem['paid_only'] else '|')

            if problem['status'] == 'ac':
                solutions = []
                submissions = self.get_submissionStatus(
                    problem['stat']['question__title_slug'])

                for lang in langs:
                    if lang in submissions.keys():
                        directory = get_directory(lang=lang,
                                                  problemID=problemID,
                                                  extension=langs[lang]['extension'])
                        solutions.append(
                            '[' + langs[lang]['display_lang'] + '](' + directory + ')')
                readme.write(', '.join(solutions))
            readme.write('|')

            if problem['status'] == 'ac' and should_write_solutions:
                self.write_solutions(problem=problem)

            if problem['difficulty']['level'] == 1:
                readme.write('Easy')
            elif problem['difficulty']['level'] == 2:
                readme.write('Medium')
            else:
                readme.write('Hard')
            readme.write('|\n')

    def write_solutions(self, problem: list):
        problemID = str(problem['stat']['frontend_question_id']).zfill(4)
        submissions = self.get_submissionStatus(
            problem['stat']['question__title_slug'])

        for lang in langs:
            if lang in submissions.keys():
                directory = get_directory(lang=lang,
                                          problemID=problemID,
                                          extension=langs[lang]['extension'])

                with open('.' + directory, encoding='utf-8', mode='w+') as f:
                    print('Write solutions: ' + problemID +
                          langs[lang]['extension'])
                    code = self.getCodeByID(
                        submissionID=submissions[lang]['id'])
                    f.write(code)

    def write_mkdocs(self, problems: list, lang: str, highlight: str, extension: str):
        if not os.path.exists('../docs'):
            os.makedirs('../docs')

        if not os.path.exists('../docs/' + lang):
            os.makedirs('../docs/' + lang)

        # Google Sheets scope
        scope = ['https://spreadsheets.google.com/feeds',
                 'https://www.googleapis.com/auth/spreadsheets',
                 'https://www.googleapis.com/auth/drive.file',
                 'https://www.googleapis.com/auth/drive']
        creds = ServiceAccountCredentials.from_json_keyfile_name(
            'creds.json', scope)
        client = gspread.authorize(creds)
        sheet = client.open('LeetCode API').sheet1
        sheetsRecord = sheet.get_all_records()

        for i, problem in enumerate(problems):
            # Get all Google Sheets records
            rowObject = sheetsRecord[i]
            tags = rowObject['Tags'].split(', ')
            emoji = rowObject['Emoji']
            timeComplexity = rowObject['Time']
            spaceComplexity = rowObject['Space']

            if i % 100 == 0:
                path = '../docs/' + lang + '/' + get_mkdocs_path_name(i)
                if not os.path.exists(path):
                    os.makedirs(path)

            if i % 10 == 0:
                file = path + '/' + get_mkdocs_file_name(i)
                f = open(file, 'w+')
            else:
                f = open(file, 'a+')

            stars = '[$' + '\\star' * problem['difficulty']['level'] + '$]'
            title = ' '.join(['##',
                              str(i + 1) + '.',
                              problem['stat']['question__title'],
                              stars +
                              '(https://leetcode.com/problems/%s)' % problem['stat']['question__title_slug']
                              ])
            if emoji:
                title += ' ' + emoji

            f.write(title)
            f.write('\n')

            try:
                codeSnippet = open('../solutions/' + lang + '/' +
                                   str(i + 1).zfill(4) + extension, 'r').read()
                f.write('\n')

                # Write tags
                tagStrings = []
                for tag in tags:
                    if tag in classTags:
                        name = '%20'.join(classTags[tag]['name'].split())
                        color = classTags[tag]['color']
                        tagStrings.append(
                            '![](https://img.shields.io/badge/-%s-%s.svg?style=flat-square)' % (name, color))

                if tagStrings:
                    f.write(' '.join(tagStrings))
                    f.write('\n\n')

                # Write space and time complexity
                complexityStrings = []
                if timeComplexity != '':
                    complexityStrings.append('- [x] Time: %s' % timeComplexity)
                if spaceComplexity != '':
                    complexityStrings.append(
                        '- [x] Space: %s' % spaceComplexity)

                if complexityStrings:
                    f.write('\n'.join(complexityStrings))
                    f.write('\n\n')

                # Write code snippet
                f.write('```' + highlight + '\n')
                f.write(codeSnippet)
                f.write('\n```\n' if lang in ['cpp', 'java'] else '```\n')

            except FileNotFoundError:
                # print('No such file or directory:',
                #       str(i + 1).zfill(4) + extension)
                pass

            if i % 10 != 9:
                f.write('\n')


if __name__ == '__main__':
    LeetCode = LeetCode()

    problems = LeetCode.get_problems(API_URL)
    problems.sort(key=lambda x: x['stat']['frontend_question_id'])

    print('There are %s problems!' % len(problems))

    parser = argparse.ArgumentParser(description='Crawl LeetCode submissions.')
    parser.add_argument('--problem', '-p', type=int,
                        help='get a specific problem')
    parser.add_argument('--range', '-r', type=int, nargs='*',
                        help='get problems of range [a, b]')
    parser.add_argument('--mkdocs', '-m', type=str,
                        help='write mkdocs markdown files')
    parser.add_argument('--readme', '-rm', action='store_true',
                        help='write readme only')
    args = parser.parse_args()

    if len(sys.argv) < 2:
        LeetCode.write_readme(problems=problems,
                              should_write_solutions=True)

    if args.problem:
        question_id = args.problem
        LeetCode.write_solutions(problems[question_id - 1])

    if args.range:
        start = args.range[0]
        end = args.range[1]
        problems = problems[start - 1: end]
        for problem in problems:
            LeetCode.write_solutions(problem)

    if args.mkdocs:

        if args.mkdocs == 'all':
            for lang in langs.keys():
                LeetCode.write_mkdocs(problems=problems,
                                      lang=lang,
                                      highlight=langs[lang]['highlight'],
                                      extension=langs[lang]['extension'])
        else:
            LeetCode.write_mkdocs(problems=problems,
                                  lang=args.mkdocs,
                                  highlight=langs[lang]['highlight'],
                                  extension=langs[lang]['extension'])

    if args.readme:
        LeetCode.write_readme(problems=problems, should_write_solutions=False)
