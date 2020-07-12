class Solution {
  public List<Integer> findSubstring(String s, String[] words) {
    if (s.isEmpty() || words.length == 0)
      return new ArrayList<>();

    final int n = words[0].length();

    List<Integer> ans = new ArrayList<>();
    Map<String, Integer> count = new HashMap<>();

    for (String word : words)
      count.put(word, count.getOrDefault(word, 0) + 1);

    for (int i = 0; i <= s.length() - words.length * n; ++i) {
      Map<String, Integer> seen = new HashMap<>();
      int j = 0;
      for (; j < words.length; ++j) {
        String word = s.substring(i + j * n, i + j * n + n);
        seen.put(word, seen.getOrDefault(word, 0) + 1);
        if (seen.get(word) > count.getOrDefault(word, 0))
          break;
      }
      if (j == words.length)
        ans.add(i);
    }

    return ans;
  }
}