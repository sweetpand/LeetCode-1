class Solution {
  public List<String> findWords(char[][] board, String[] words) {
    for (String word : words)
      insert(word);

    List<String> ans = new ArrayList<>();

    for (int i = 0; i < board.length; ++i)
      for (int j = 0; j < board[0].length; ++j)
        dfs(board, i, j, root, ans);

    return ans;
  }

  private class TrieNode {
    private TrieNode[] children = new TrieNode[26];
    private String word;
  }

  private TrieNode root = new TrieNode();

  private void insert(final String word) {
    TrieNode node = root;
    for (char c : word.toCharArray()) {
      int index = c - 'a';
      if (node.children[index] == null)
        node.children[index] = new TrieNode();
      node = node.children[index];
    }
    node.word = word;
  }

  private void dfs(char[][] board, int i, int j, TrieNode node, List<String> ans) {
    if (i < 0 || i >= board.length || j < 0 || j >= board[0].length || board[i][j] == '*')
      return;

    char c = board[i][j];
    int index = (int) (c - 'a');
    TrieNode next = node.children[index];
    if (next == null)
      return;
    if (next.word != null) {
      ans.add(next.word);
      next.word = null;
    }

    board[i][j] = '*';
    dfs(board, i + 1, j, next, ans);
    dfs(board, i - 1, j, next, ans);
    dfs(board, i, j + 1, next, ans);
    dfs(board, i, j - 1, next, ans);
    board[i][j] = c;
  }
}