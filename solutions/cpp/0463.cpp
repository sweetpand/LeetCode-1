class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    int islands = 0;
    int neighbors = 0;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j]) {
          ++islands;
          if (i + 1 < m && grid[i + 1][j]) ++neighbors;
          if (j + 1 < n && grid[i][j + 1]) ++neighbors;
        }

    return islands * 4 - neighbors * 2;
  }
};