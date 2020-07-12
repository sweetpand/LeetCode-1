class Solution {
  public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
    List<List<String>> ans = new ArrayList<>();
    Set<String> set = new HashSet<>(wordList);

    if (!set.contains(endWord))
      return ans;

    Set<String> set1 = new HashSet<>(Arrays.asList(beginWord));
    Map<String, List<String>> map = new HashMap<>();
    boolean isFound = false;

    while (!set1.isEmpty() && !isFound) {
      for (String word : set1)
        set.remove(word);
      Set<String> tempSet = new HashSet<>();
      for (String parent : set1) {
        char[] word = parent.toCharArray();
        for (int i = 0; i < word.length; ++i) {
          char c = word[i];
          for (char j = 'a'; j <= 'z'; ++j) {
            word[i] = j;
            String newWord = String.valueOf(word);
            if (newWord.equals(endWord)) {
              if (!map.containsKey(parent))
                map.put(parent, new ArrayList<>());
              map.get(parent).add(newWord);
              isFound = true;
            } else if (set.contains(newWord) && !isFound) {
              tempSet.add(newWord);
              if (!map.containsKey(parent))
                map.put(parent, new ArrayList<>());
              map.get(parent).add(newWord);
            }
          }
          word[i] = c;
        }
      }
      set1 = tempSet;
    }

    if (isFound) {
      List<String> path = new ArrayList<>(Arrays.asList(beginWord));
      dfs(map, beginWord, endWord, path, ans);
    }

    return ans;
  }

  private void dfs(Map<String, List<String>> map, String word, String endWord, List<String> path,
      List<List<String>> ans) {
    if (word.equals(endWord)) {
      ans.add(new ArrayList<>(path));
      return;
    }
    if (!map.containsKey(word))
      return;

    for (String child : map.get(word)) {
      path.add(child);
      dfs(map, child, endWord, path, ans);
      path.remove(path.size() - 1);
    }
  }
}