class Solution {
  public String addBinary(String a, String b) {
    String ans = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (carry == 1 || i >= 0 || j >= 0) {
      if (i >= 0)
        carry += a.charAt(i--) - '0';
      if (j >= 0)
        carry += b.charAt(j--) - '0';
      ans = (char) (carry % 2 + '0') + ans;
      carry >>= 1;
    }

    return ans;
  }
}