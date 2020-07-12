class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length()) return false;

    vector<vector<bool>> dp(s1.length() + 1, vector<bool>(s2.length() + 1));

    for (int i = 0; i <= s1.length(); ++i)
      for (int j = 0; j <= s2.length(); ++j)
        if (i == 0 && j == 0)
          dp[0][0] = true;
        else if (i == 0)
          dp[0][j] = s2[j - 1] == s3[j - 1] && dp[0][j - 1];
        else if (j == 0)
          dp[i][0] = s1[i - 1] == s3[i - 1] && dp[i - 1][0];
        else
          dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) ||
                     (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);

    return dp[s1.length()][s2.length()];
  }
};