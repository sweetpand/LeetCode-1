class Solution {
 public:
  int minCut(string s) {
    const int n = s.length();

    vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));
    vector<int> dp(n, n);

    for (int length = 2; length <= n; ++length)
      for (int i = 0, j = length - 1; j < n; ++i, ++j)
        isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i + 1][j - 1];

    for (int i = 0; i < n; ++i) {
      if (isPalindrome[0][i]) {
        dp[i] = 0;
        continue;
      }
      for (int j = 0; j < i; ++j)
        if (isPalindrome[j + 1][i])
          dp[i] = min(dp[i], dp[j] + 1);
    }

    return dp[n - 1];
  }
};