class Solution {
 public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string>& wordList) {
    unordered_set<string> wordListSet(begin(wordList), end(wordList));
    if (!wordListSet.count(endWord)) return {}; // prune (still AC if this line is removed)

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parentToWords;
    unordered_set<string> currentLevelWords{beginWord};
    bool isFound = false;

    while (!currentLevelWords.empty() && !isFound) {
      // remove words in current level
      for (const string& word : currentLevelWords)
        wordListSet.erase(word);
      unordered_set<string> nextLevelWords;
      // `parent` will be used as a key in `parentToWords`
      for (const string& parent : currentLevelWords) {
        string nextWord = parent;
        // enumerate next level words
        for (int i = 0; i < nextWord.length(); ++i) {
          const char cache = nextWord[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            nextWord[i] = c;
            if (wordListSet.count(nextWord)) {
              if (nextWord == endWord)
                isFound = true;
              nextLevelWords.insert(nextWord);
              parentToWords[parent].push_back(nextWord);
            }
          }
          nextWord[i] = cache;
        }
      }
      if (isFound) break;
      swap(currentLevelWords, nextLevelWords);
    }

    // construct the ans by `parentToWords`
    function<void(const string&, vector<string>&)> dfs =
        [&](const string& word, vector<string>& path) {
          if (word == endWord) {
            ans.push_back(path);
            return;
          }
          if (!parentToWords.count(word)) return;

          for (const string& child : parentToWords[word]) {
            path.push_back(child);
            dfs(child, path);
            path.pop_back();
          }
        };

    if (isFound) {
      vector<string> path{beginWord};
      dfs(beginWord, path);
    }

    return ans;
  }
};