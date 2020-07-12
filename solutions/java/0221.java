class Solution {
  public int maximalSquare(char[][] matrix) {
    if (matrix.length == 0)
      return 0;

    int[] dp = new int[matrix[0].length];
    int maxLength = 0;
    int prev = 0;

    for (int i = 0; i < matrix.length; ++i)
      for (int j = 0; j < matrix[0].length; ++j) {
        int cache = dp[j];
        if (i == 0 || j == 0 || matrix[i][j] == '0')
          dp[j] = matrix[i][j] == '1' ? 1 : 0;
        else
          dp[j] = Math.min(dp[j], Math.min(dp[j - 1], prev)) + 1;
        maxLength = Math.max(maxLength, dp[j]);
        prev = cache;
      }

    return maxLength * maxLength;
  }
}