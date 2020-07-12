class Solution {
  public String smallestSubsequence(String text) {
    StringBuilder ans = new StringBuilder();
    int[] count = new int[26];
    boolean[] used = new boolean[26];

    for (char c : text.toCharArray())
      ++count[c - 'a'];

    for (char c : text.toCharArray()) {
      --count[c - 'a'];
      if (used[c - 'a'])
        continue;
      while (ans.length() > 0 && ans.charAt(ans.length() - 1) > c && count[ans.charAt(ans.length() - 1) - 'a'] > 0) {
        used[ans.charAt(ans.length() - 1) - 'a'] = false;
        ans.setLength(ans.length() - 1);
      }
      ans.append(c);
      used[c - 'a'] = true;
    }

    return ans.toString();
  }
}