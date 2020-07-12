class Solution {
  public char[][] updateBoard(char[][] board, int[] click) {
    if (board[click[0]][click[1]] == 'M') {
      board[click[0]][click[1]] = 'X';
      return board;
    }

    dfs(board, click[0], click[1]);

    return board;
  }

  private int[][] dirs = new int[][] { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 }, { 1, -1 }, { 1, 0 },
      { 1, 1 } };

  private void dfs(char[][] board, int i, int j) {
    if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] != 'E')
      return;

    int minesCount = 0;
    for (final int[] dir : dirs) {
      int x = i + dir[0];
      int y = j + dir[1];
      if (0 <= x && x < board.length && 0 <= y && y < board[0].length && board[x][y] == 'M')
        ++minesCount;
    }
    board[i][j] = minesCount > 0 ? (char) ('0' + minesCount) : 'B';

    if (minesCount == 0)
      for (final int[] dir : dirs)
        dfs(board, i + dir[0], j + dir[1]);
  }
}