class Trie {
  public void insert(String word) {
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
    TrieNode node = find(word);
    return node != null && node.isWord;
  }

  public boolean startsWith(String prefix) {
    return find(prefix) != null;
  }

  private class TrieNode {
    private TrieNode[] children = new TrieNode[26];
    private boolean isWord = false;
  }

  private TrieNode root = new TrieNode();

  private TrieNode find(String prefix) {
    TrieNode node = root;
    for (int i = 0; i < prefix.length(); ++i) {
      int index = (int) (prefix.charAt(i) - 'a');
      if (node.children[index] == null)
        return null;
      node = node.children[index];
    }
    return node;
  }
}