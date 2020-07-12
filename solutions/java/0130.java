class Solution {
  public void solve(char[][] board) {
    if (board.length == 0)
      return;

    final int m = board.length;
    final int n = board[0].length;

    for (int i = 0; i < m; ++i) {
      dfs(board, i, 0);
      dfs(board, i, n - 1);
    }

    for (int j = 1; j < n - 1; ++j) {
      dfs(board, 0, j);
      dfs(board, m - 1, j);
    }

    for (char[] row : board)
      for (int i = 0; i < row.length; ++i)
        row[i] = row[i] == '.' ? 'O' : 'X';
  }

  private void dfs(char[][] board, int i, int j) {
    if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != 'O')
      return;

    board[i][j] = '.';
    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
  }
}