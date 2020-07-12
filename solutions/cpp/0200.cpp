class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;

    const int m = grid.size();
    const int n = grid[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};

    int ans = 0;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == '1') {
          ++ans;
          grid[i][j] = '0';
          queue<pair<int, int>> queue{{{i, j}}};
          while (!queue.empty()) {
            const auto [x, y] = queue.front(); queue.pop();
            for (int k = 0; k < 4; ++k) {
              const int r = x + dirs[k];
              const int c = y + dirs[k + 1];
              if (r < 0 || r == m || c < 0 || c == n) continue;
              if (grid[r][c] == '0') continue;
              queue.push({r, c});
              grid[r][c] = '0';
            }
          }
        }

    return ans;
  }
};