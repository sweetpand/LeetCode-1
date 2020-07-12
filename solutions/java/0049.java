class Solution {
  public List<List<String>> groupAnagrams(String[] strs) {
    List<List<String>> ans = new ArrayList<>();
    Map<String, List<String>> map = new HashMap<>();

    for (final String str : strs) {
      char[] charArray = str.toCharArray();
      Arrays.sort(charArray);
      String s = String.valueOf(charArray);
      map.computeIfAbsent(s, k -> new ArrayList<>()).add(str);
    }

    return new ArrayList<>(map.values());
  }
}