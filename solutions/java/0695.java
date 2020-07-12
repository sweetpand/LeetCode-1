class Solution {
  public int maxAreaOfIsland(int[][] grid) {
    int ans = 0;
    boolean[][] seen = new boolean[grid.length][grid[0].length];

    for (int i = 0; i < grid.length; ++i)
      for (int j = 0; j < grid[0].length; ++j)
        ans = Math.max(ans, dfs(grid, i, j, seen));

    return ans;
  }

  private int dfs(int[][] grid, int i, int j, boolean[][] seen) {
    if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length)
      return 0;
    if (grid[i][j] == 0 || seen[i][j])
      return 0;

    seen[i][j] = true;

    return 1 + dfs(grid, i + 1, j, seen) + dfs(grid, i - 1, j, seen) + dfs(grid, i, j + 1, seen)
        + dfs(grid, i, j - 1, seen);
  }
}