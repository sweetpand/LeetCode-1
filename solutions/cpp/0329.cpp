class Solution {
 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;

    const int m = matrix.size();
    const int n = matrix[0].size();

    int ans = 0;
    vector<vector<int>> memo(m, vector<int>(n));

    function<int(int, int, int)> dfs = [&](int i, int j, int maxi) {
      if (i < 0 || i == m || j < 0 || j == n) return 0;
      if (matrix[i][j] <= maxi) return 0;
      if (memo[i][j]) return memo[i][j];

      return memo[i][j] = 1 + max({dfs(i + 1, j, matrix[i][j]),
                                   dfs(i - 1, j, matrix[i][j]),
                                   dfs(i, j + 1, matrix[i][j]),
                                   dfs(i, j - 1, matrix[i][j])});
    };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        ans = max(ans, dfs(i, j, INT_MIN));

    return ans;
  }
};