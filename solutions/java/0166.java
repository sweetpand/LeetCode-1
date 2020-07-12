class Solution {
  public String fractionToDecimal(int numerator, int denominator) {
    if (numerator == 0)
      return "0";

    String ans = "";

    if (numerator < 0 ^ denominator < 0)
      ans += "-";

    long n = Math.abs((long) numerator);
    long d = Math.abs((long) denominator);

    ans += String.valueOf(n / d);

    if (n % d == 0)
      return ans;

    ans += ".";
    Map<Long, Integer> map = new HashMap<>();

    for (long r = n % d; r > 0; r %= d) {
      if (map.containsKey(r)) {
        ans = ans.substring(0, map.get(r)) + "(" + ans.substring(map.get(r), ans.length()) + ")";
        break;
      }
      map.put(r, ans.length());
      r *= 10;
      ans += String.valueOf(r / d);
    }

    return ans;
  }
}