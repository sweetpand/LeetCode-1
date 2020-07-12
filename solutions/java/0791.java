class Solution {
  public String customSortString(String S, String T) {
    String ans = new String("");
    int[] count = new int[26];

    for (char c : T.toCharArray())
      ++count[c - 'a'];

    for (char c : S.toCharArray())
      while (count[c - 'a']-- > 0)
        ans += c;

    for (char c = 'a'; c <= 'z'; ++c)
      while (count[c - 'a']-- > 0)
        ans += c;

    return ans;
  }
}