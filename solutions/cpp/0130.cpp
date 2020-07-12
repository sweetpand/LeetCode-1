class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    if (board.empty()) return;

    const int m = board.size();
    const int n = board[0].size();

    function<void(int, int)> dfs = [&](int i, int j) {
      if (i < 0 || i == m || j < 0 || j == n) return;
      if (board[i][j] != 'O') return;

      board[i][j] = '*';
      dfs(i + 1, j);
      dfs(i - 1, j);
      dfs(i, j + 1);
      dfs(i, j - 1);
    };

    for (int i = 0; i < m; ++i) {
      dfs(i, 0);
      dfs(i, n - 1);
    }

    for (int j = 1; j < n - 1; ++j) {
      dfs(0, j);
      dfs(m - 1, j);
    }

    for (vector<char>& row : board)
      for (char& c : row)
        c = (c == '*' ? 'O' : 'X');
  }
};