class Solution {
  public boolean wordPattern(String pattern, String str) {
    String[] words = str.split(" ");
    if (words.length != pattern.length())
      return false;

    Map<Character, Integer> charMap = new HashMap<>();
    Map<String, Integer> strMap = new HashMap<>();

    for (Integer i = 0; i < pattern.length(); ++i)
      if (charMap.put(pattern.charAt(i), i) != strMap.put(words[i], i))
        return false;

    return true;
  }
}