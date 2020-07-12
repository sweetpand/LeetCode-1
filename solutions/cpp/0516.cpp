class Solution {
 public:
  int longestPalindromeSubseq(string s) {
    const int n = s.length();

    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int length = 2; length <= n; ++length)
      for (int i = 0; i + length - 1 < n; ++i) {
        const int j = i + length - 1;
        if (s[i] == s[j])
          dp[i][j] = 2 + dp[i + 1][j - 1];
        else
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      }

    return dp[0][n - 1];
  }
};