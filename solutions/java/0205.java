class Solution {
  public boolean isIsomorphic(String s, String t) {
    Map<Character, Integer> map_s = new HashMap<>();
    Map<Character, Integer> map_t = new HashMap<>();

    for (Integer i = 0; i < s.length(); ++i)
      if (map_s.put(s.charAt(i), i) != map_t.put(t.charAt(i), i))
        return false;

    return true;
  }
}