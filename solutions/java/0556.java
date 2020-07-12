class Solution {
  public int nextGreaterElement(int n) {
    String s = nextPermutation(String.valueOf(n).toCharArray());
    long ans = Long.valueOf(s);

    return ans > Integer.MAX_VALUE || ans <= (long) n ? -1 : (int) ans;
  }

  private String nextPermutation(char[] charArray) {
    int i;
    for (i = charArray.length - 2; i >= 0; --i)
      if (charArray[i] < charArray[i + 1])
        break;

    if (i >= 0) {
      int j;
      for (j = charArray.length - 1; j > i; --j)
        if (charArray[j] > charArray[i])
          break;
      swap(charArray, i, j);
    }

    reverse(charArray, i + 1, charArray.length - 1);

    return new String(charArray);
  }

  private void reverse(char[] charArray, int l, int r) {
    while (l < r)
      swap(charArray, l++, r--);
  }

  private void swap(char[] charArray, int i, int j) {
    char temp = charArray[i];
    charArray[i] = charArray[j];
    charArray[j] = temp;
  }
}