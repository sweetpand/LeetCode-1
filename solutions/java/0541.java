class Solution {
  public String reverseStr(String s, int k) {
    char[] charArray = s.toCharArray();

    for (int i = 0; i < charArray.length; i += 2 * k) {
      int l = i;
      int r = Math.min(i + k - 1, charArray.length - 1);
      while (l < r) {
        char temp = charArray[l];
        charArray[l++] = charArray[r];
        charArray[r--] = temp;
      }
    }

    return new String(charArray);
  }
}