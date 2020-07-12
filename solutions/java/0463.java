class Solution {
  public int islandPerimeter(int[][] grid) {
    final int m = grid.length;
    final int n = grid[0].length;

    int islands = 0;
    int neighbors = 0;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid[i][j] == 1) {
          ++islands;
          if (i + 1 < m && grid[i + 1][j] == 1)
            ++neighbors;
          if (j + 1 < n && grid[i][j + 1] == 1)
            ++neighbors;
        }

    return islands * 4 - neighbors * 2;
  }
}