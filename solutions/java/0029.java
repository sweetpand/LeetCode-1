class Solution {
  public int divide(int dividend, int divisor) {
    if (dividend == Integer.MIN_VALUE && divisor == -1)
      return Integer.MAX_VALUE;

    long ans = 0;
    long dvd = Math.abs((long) dividend);
    long dvs = Math.abs((long) divisor);
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;

    while (dvd >= dvs) {
      long m = 1;
      long temp = dvs;
      while (temp << 1 <= dvd) {
        m <<= 1;
        temp <<= 1;
      }
      dvd -= temp;
      ans += m;
    }

    return sign * (int) ans;
  }
}