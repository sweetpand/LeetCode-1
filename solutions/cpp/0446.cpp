class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int ans = 0;
    // dp[i][j] := subsequences end w/ A[j] A[i]
    vector<vector<int>> dp(A.size(), vector<int>(A.size()));
    unordered_map<long, vector<int>> numToIndices;

    for (int i = 0; i < A.size(); ++i)
      numToIndices[A[i]].push_back(i);

    for (int i = 0; i < A.size(); ++i)
      for (int j = 0; j < i; ++j) {
        const long target = (long)A[j] * 2 - A[i];
        if (numToIndices.count(target)) {
          for (const int k : numToIndices[target])
            if (k < j)
              dp[i][j] += (dp[j][k] + 1);
        }
        ans += dp[i][j];
      }

    return ans;
  }
};