class Solution {
  public int countPalindromicSubsequences(String S) {
    final int n = S.length();
    final long kMod = (long) 1e9 + 7;

    long[][] dp = new long[n][n];

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int length = 2; length <= n; ++length)
      for (int i = 0; i <= n - length; ++i) {
        final int j = i + length - 1;
        if (S.charAt(i) == S.charAt(j)) {
          int lo = i + 1;
          int hi = j - 1;
          while (lo <= hi && S.charAt(lo) != S.charAt(i))
            ++lo;
          while (lo <= hi && S.charAt(hi) != S.charAt(i))
            --hi;
          if (lo > hi)
            dp[i][j] = dp[i + 1][j - 1] * 2 + 2;
          else if (lo == hi)
            dp[i][j] = dp[i + 1][j - 1] * 2 + 1;
          else
            dp[i][j] = dp[i + 1][j - 1] * 2 - dp[lo + 1][hi - 1];
        } else
          dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
        dp[i][j] = (dp[i][j] + kMod) % kMod;
      }

    return (int) dp[0][n - 1];
  }
}