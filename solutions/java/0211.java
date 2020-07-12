class WordDictionary {
  public void addWord(String word) {
    TrieNode node = root;
    for (char c : word.toCharArray()) {
      int index = c - 'a';
      if (node.children[index] == null)
        node.children[index] = new TrieNode();
      node = node.children[index];
    }
    node.isWord = true;
  }

  public boolean search(String word) {
    return dfs(word, 0, root);
  }

  private class TrieNode {
    private TrieNode[] children = new TrieNode[26];
    private boolean isWord = false;
  }

  private TrieNode root = new TrieNode();

  private boolean dfs(String word, int depth, TrieNode node) {
    if (depth == word.length())
      return node.isWord;
    if (word.charAt(depth) != '.') {
      TrieNode next = node.children[word.charAt(depth) - 'a'];
      return next != null ? dfs(word, depth + 1, next) : false;
    }

    for (int i = 0; i < 26; ++i)
      if (node.children[i] != null && dfs(word, depth + 1, node.children[i]))
        return true;

    return false;
  }
}