class Solution {
  public int superPow(int a, int[] b) {
    int ans = 1;

    a %= k;
    for (int i : b)
      ans = powMod(ans, 10) * powMod(a, i) % k;

    return ans;
  }

  private final int k = 1337;

  private int powMod(int x, int y) {
    int pow = 1;

    for (int i = 0; i < y; ++i)
      pow = (pow * x) % k;

    return pow;
  }
}