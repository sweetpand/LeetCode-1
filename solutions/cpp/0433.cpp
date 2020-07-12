class Solution {
 public:
  int minMutation(string start, string end, vector<string>& bank) {
    unordered_set<string> bankSet{bank.begin(), bank.end()};
    if (!bankSet.count(end)) return -1;

    int ans = 0;
    queue<string> q{{start}};

    while (!q.empty()) {
      ++ans;
      for (int i = q.size(); i > 0; --i) {
        string word = q.front(); q.pop();
        for (int i = 0; i < word.length(); ++i) {
          const char cache = word[i];
          for (const char c : {'A', 'C', 'G', 'T'}) {
            word[i] = c;
            if (word == end) return ans;
            if (bankSet.count(word)) {
              bankSet.erase(word);
              q.push(word);
            }
          }
          word[i] = cache;
        }
      }
    }

    return -1;
  }
};