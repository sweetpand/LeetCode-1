class Solution {
  public boolean exist(char[][] board, String word) {
    if (board.length == 0)
      return false;

    for (int i = 0; i < board.length; ++i)
      for (int j = 0; j < board[0].length; ++j)
        if (dfs(board, word, i, j, 0))
          return true;

    return false;
  }

  private boolean dfs(char[][] board, String word, int i, int j, int pos) {
    if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != word.charAt(pos)
        || board[i][j] == '*')
      return false;
    if (pos == word.length() - 1)
      return true;

    char c = board[i][j];
    board[i][j] = '*';
    boolean flag = dfs(board, word, i + 1, j, pos + 1) || dfs(board, word, i - 1, j, pos + 1)
        || dfs(board, word, i, j + 1, pos + 1) || dfs(board, word, i, j - 1, pos + 1);
    board[i][j] = c;

    return flag;
  }
}