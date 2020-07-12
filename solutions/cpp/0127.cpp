class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordListSet(begin(wordList), end(wordList));
    if (!wordListSet.count(endWord)) return 0;

    int ans = 0;
    queue<string> q{{beginWord}};

    while (!q.empty()) {
      ++ans;
      for (int i = q.size(); i > 0; --i) {
        string word = q.front(); q.pop();
        for (int i = 0; i < word.length(); ++i) {
          const char cache = word[i];
          for (char c = 'a'; c <= 'z'; ++c) {
            word[i] = c;
            if (word == endWord) return ans + 1;
            if (wordListSet.count(word)) {
              wordListSet.erase(word);
              q.push(word);
            }
          }
          word[i] = cache;
        }
      }
    }

    return 0;
  }
};