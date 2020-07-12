class Solution {
  public String orderlyQueue(String S, int K) {
    if (K > 1) {
      char[] charArray = S.toCharArray();
      Arrays.sort(charArray);
      return String.valueOf(charArray);
    }

    String ans = S;

    for (int i = 1; i < S.length(); ++i) {
      String S2 = S.substring(i) + S.substring(0, i);
      if (ans.compareTo(S2) > 0)
        ans = S2;
    }

    return ans;
  }
}