class Solution {
  public boolean checkInclusion(String s1, String s2) {
    int[] count1 = new int[26];
    int required = s1.length();

    for (char c : s1.toCharArray())
      ++count1[c - 'a'];

    for (int r = 0; r < s2.length(); ++r) {
      if (--count1[s2.charAt(r) - 'a'] >= 0)
        --required;
      if (r >= s1.length())
        if (++count1[s2.charAt(r - s1.length()) - 'a'] > 0)
          ++required;
      if (required == 0)
        return true;
    }

    return false;
  }
}