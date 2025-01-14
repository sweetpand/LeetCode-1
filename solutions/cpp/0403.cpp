class Solution {
 public:
  bool canCross(vector<int>& stones) {
    const int n = stones.size();

    vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
    dp[0][1] = true;

    for (int i = 1; i < n; ++i)
      for (int j = i - 1; j >= 0; --j) {
        const int k = stones[i] - stones[j];
        if (k <= n && dp[j][k]) {
          dp[i][k - 1] = true;
          dp[i][k] = true;
          dp[i][k + 1] = true;
        }
      }

    return any_of(begin(dp.back()), end(dp.back()),
                  [](bool val) { return val; });
  }
};