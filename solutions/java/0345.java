class Solution {
  public String reverseVowels(String s) {
    String vowels = "aeiouAEIOU";
    char[] charArray = s.toCharArray();
    int l = 0;
    int r = s.length() - 1;

    while (l < r) {
      while (l < r && !vowels.contains("" + charArray[l]))
        ++l;
      while (l < r && !vowels.contains("" + charArray[r]))
        --r;
      char temp = charArray[l];
      charArray[l++] = charArray[r];
      charArray[r--] = temp;
    }

    return String.valueOf(charArray);
  }
}