class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet{begin(wordDict), end(wordDict)};
    unordered_map<string, vector<string>> memo;

    function<vector<string>(const string&)> dfs = [&](const string s) {
      if (memo.count(s)) return memo[s];

      vector<string> ans;

      if (wordSet.count(s)) ans.push_back(s);

      for (int i = 1; i < s.length(); ++i) {
        const string rightWord = s.substr(i);
        if (wordSet.count(rightWord))
          for (const string word : dfs(s.substr(0, i)))
            ans.push_back(word + " " + rightWord);
      }

      return memo[s] = ans;
    };

    return dfs(s);
  }
};