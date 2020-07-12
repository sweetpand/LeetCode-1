class Solution {
  public List<List<Integer>> palindromePairs(String[] words) {
    List<List<Integer>> ans = new ArrayList<>();
    Map<String, Integer> map = new HashMap<>();

    for (int i = 0; i < words.length; ++i) {
      StringBuilder sb = new StringBuilder(words[i]);
      map.put(sb.reverse().toString(), i);
    }

    for (int i = 0; i < words.length; ++i) {
      if (map.containsKey("") && map.get("") != i && isPalindrome(words[i]))
        ans.add(Arrays.asList(i, map.get("")));

      for (int j = 1; j <= words[i].length(); ++j) {
        String l = words[i].substring(0, j);
        String r = words[i].substring(j, words[i].length());
        if (map.containsKey(l) && map.get(l) != i && isPalindrome(r))
          ans.add(Arrays.asList(i, map.get(l)));
        if (map.containsKey(r) && map.get(r) != i && isPalindrome(l))
          ans.add(Arrays.asList(map.get(r), i));
      }
    }

    return ans;
  }

  private boolean isPalindrome(String s) {
    int l = 0;
    int r = s.length() - 1;

    while (l < r)
      if (s.charAt(l++) != s.charAt(r--))
        return false;

    return true;
  }
}