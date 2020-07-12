class Solution {
  public int titleToNumber(String s) {
    int ans = 0;

    for (char c : s.toCharArray())
      ans = ans * 26 + c - '@';

    return ans;
  }
}