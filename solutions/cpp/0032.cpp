class Solution {
 public:
  int longestValidParentheses(string s) {
    int ans = 0;
    s = ")" + s;
    vector<int> dp(s.length());

    for (int i = 1; i < s.length(); ++i)
      if (s[i] == ')' && s[i - dp[i - 1] - 1] == '(') {
        dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
        ans = max(ans, dp[i]);
      }

    return ans;
  }
};