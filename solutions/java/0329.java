class Solution {
  public int longestIncreasingPath(int[][] matrix) {
    if (matrix.length == 0)
      return 0;

    int ans = 0;
    int[][] cached = new int[matrix.length][matrix[0].length];

    for (int i = 0; i < matrix.length; ++i)
      for (int j = 0; j < matrix[0].length; ++j)
        ans = Math.max(ans, dfs(matrix, i, j, Integer.MIN_VALUE, cached));

    return ans;
  }

  private int dfs(int[][] matrix, int i, int j, int max, int[][] cached) {
    if (i < 0 || i >= matrix.length || j < 0 || j >= matrix[0].length || matrix[i][j] <= max)
      return 0;
    if (cached[i][j] != 0)
      return cached[i][j];

    int a = dfs(matrix, i + 1, j, matrix[i][j], cached);
    int b = dfs(matrix, i - 1, j, matrix[i][j], cached);
    int c = dfs(matrix, i, j + 1, matrix[i][j], cached);
    int d = dfs(matrix, i, j - 1, matrix[i][j], cached);
    cached[i][j] = 1 + Math.max(Math.max(a, b), Math.max(c, d));

    return cached[i][j];
  }
}