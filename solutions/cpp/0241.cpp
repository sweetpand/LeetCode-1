class Solution {
 public:
  vector<int> diffWaysToCompute(string input) {
    unordered_map<string, vector<int>> memo;

    function<vector<int>(const string&)> ways = [&](const string& s) {
      if (memo.count(s)) return memo[s];

      vector<int> ans;

      for (int i = 0; i < s.length(); ++i)
        if (ispunct(s[i]))
          for (int a : ways(s.substr(0, i)))
            for (int b : ways(s.substr(i + 1)))
              ans.push_back(s[i] == '+' ? a + b : s[i] == '-' ? a - b : a * b);

      return memo[s] = ans.empty() ? vector<int>{stoi(s)} : ans;
    };

    return ways(input);
  }
};