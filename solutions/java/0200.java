class Solution {
  public int numIslands(char[][] grid) {
    if (grid.length == 0)
      return 0;

    final int m = grid.length;
    final int n = grid[0].length;

    int ans = 0;
    boolean[][] seen = new boolean[m][n];

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (!seen[i][j] && grid[i][j] == '1') {
          ++ans;
          dfs(grid, i, j, seen);
        }

    return ans;
  }

  private void dfs(char[][] grid, int i, int j, boolean[][] seen) {
    if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || seen[i][j] || grid[i][j] == '0')
      return;

    seen[i][j] = true;
    dfs(grid, i + 1, j, seen);
    dfs(grid, i - 1, j, seen);
    dfs(grid, i, j + 1, seen);
    dfs(grid, i, j - 1, seen);
  }
}