class Solution {
  public int characterReplacement(String s, int k) {
    int ans = 0;
    int maxFreq = 0;
    int[] count = new int[26];

    for (int l = 0, r = 0; r < s.length(); ++r) {
      ++count[s.charAt(r) - 'A'];
      maxFreq = Math.max(maxFreq, count[s.charAt(r) - 'A']);
      while (maxFreq + k < r - l + 1)
        --count[s.charAt(l++) - 'A'];
      ans = Math.max(ans, r - l + 1);
    }

    return ans;
  }
}