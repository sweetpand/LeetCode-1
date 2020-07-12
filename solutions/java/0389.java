class Solution {
  public char findTheDifference(String s, String t) {
    int[] count = new int[26];

    for (char c : s.toCharArray())
      ++count[c - 'a'];

    for (int i = 0; i < t.length(); ++i)
      if (--count[t.charAt(i) - 'a'] < 0)
        return t.charAt(i);

    throw new IllegalArgumentException();
  }
}