class Solution {
  public int myAtoi(String str) {
    long ans = 0;
    str = str.strip();

    if (str.isEmpty())
      return 0;

    boolean isNegative = str.charAt(0) == '-';
    if (str.charAt(0) == '-' || str.charAt(0) == '+')
      str = str.substring(1, str.length());

    for (char c : str.toCharArray()) {
      if (!Character.isDigit(c))
        break;
      ans = ans * 10 + (c - '0');
      if (isNegative && -ans <= Integer.MIN_VALUE)
        return Integer.MIN_VALUE;
      if (!isNegative && ans >= Integer.MAX_VALUE)
        return Integer.MAX_VALUE;
    }

    return isNegative ? (int) -ans : (int) ans;
  }
}