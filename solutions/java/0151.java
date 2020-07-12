class Solution {
  public String reverseWords(String s) {
    char[] charArray = s.toCharArray();

    reverse(charArray, 0, charArray.length - 1);
    reverseWords(charArray, 0, 0);

    return cleanSpaces(charArray, 0, 0);
  }

  private void reverseWords(char[] charArray, int i, int j) {
    while (i < charArray.length) {
      while (i < j || i < charArray.length && charArray[i] == ' ')
        ++i;
      while (j < i || j < charArray.length && charArray[j] != ' ')
        ++j;
      reverse(charArray, i, j - 1);
    }
  }

  private String cleanSpaces(char[] charArray, int i, int j) {
    while (j < charArray.length) {
      while (j < charArray.length && charArray[j] == ' ')
        ++j;
      while (j < charArray.length && charArray[j] != ' ')
        charArray[i++] = charArray[j++];
      while (j < charArray.length && charArray[j] == ' ')
        ++j;
      if (j < charArray.length)
        charArray[i++] = ' ';
    }

    return new String(charArray).substring(0, i);
  }

  private void reverse(char[] charArray, int l, int r) {
    while (l < r) {
      char temp = charArray[l];
      charArray[l++] = charArray[r];
      charArray[r--] = temp;
    }
  }
}