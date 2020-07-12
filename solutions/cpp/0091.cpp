class Solution {
 public:
  int numDecodings(string s) {
    const int n = s.length();

    // dp[i] := # of ways to decode s[i..n - 1]
    vector<int> dp(n + 1, 0);
    dp.back() = 1;
    dp[n - 1] = isValid(s[n - 1]);

    for (int i = n - 2; i >= 0; --i) {
      if (isValid(s[i], s[i + 1]))
        dp[i] += dp[i + 2];
      if (isValid(s[i]))
        dp[i] += dp[i + 1];
    }

    return dp[0];
  }

 private:
  bool isValid(char c) {
    return '1' <= c && c <= '9';
  }

  bool isValid(char c1, char c2) {
    return c1 == '1' || (c1 == '2' && c2 <= '6');
  }
};