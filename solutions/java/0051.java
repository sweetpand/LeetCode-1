class Solution {
  public List<List<String>> solveNQueens(int n) {
    List<List<String>> ans = new ArrayList<>();
    char[][] board = new char[n][n];

    for (int i = 0; i < n; ++i)
      Arrays.fill(board[i], '.');

    dfs(0, new boolean[n], new boolean[2 * n - 1], new boolean[2 * n - 1], board, ans);

    return ans;
  }

  private void dfs(int i, boolean[] cols, boolean[] diag1, boolean[] diag2, char[][] board, List<List<String>> ans) {
    if (i == cols.length) {
      ans.add(construct(board));
      return;
    }

    for (int j = 0; j < cols.length; ++j) {
      if (cols[j] || diag1[i + j] || diag2[j - i + cols.length - 1])
        continue;
      board[i][j] = 'Q';
      cols[j] = diag1[i + j] = diag2[j - i + cols.length - 1] = true;
      dfs(i + 1, cols, diag1, diag2, board, ans);
      cols[j] = diag1[i + j] = diag2[j - i + cols.length - 1] = false;
      board[i][j] = '.';
    }
  }

  private List<String> construct(char[][] board) {
    List<String> listBoard = new ArrayList<>();
    for (int i = 0; i < board.length; ++i)
      listBoard.add(String.valueOf(board[i]));
    return listBoard;
  }
}