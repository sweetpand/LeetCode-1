class Solution {
  public void solveSudoku(char[][] board) {
    dfs(0, board);
  }

  private boolean dfs(int s, char[][] board) {
    if (s == 81)
      return true;

    int i = s / 9;
    int j = s % 9;

    if (board[i][j] != '.')
      return dfs(s + 1, board);

    for (char c = '1'; c <= '9'; ++c)
      if (isValid(i, j, c, board)) {
        board[i][j] = c;
        if (dfs(s + 1, board))
          return true;
        board[i][j] = '.';
      }

    return false;
  }

  private boolean isValid(int row, int col, char c, char[][] board) {
    for (int i = 0; i < 9; ++i)
      if (board[i][col] == c || board[row][i] == c || board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
        return false;
    return true;
  }
}