class Solution {
  public int climbStairs(int n) {
    if (n == 1)
      return 1;

    int ans = 0;
    int prevTwoStairs = 1;
    int prevOneStair = 1;

    for (int i = 2; i <= n; ++i) {
      ans = prevTwoStairs + prevOneStair;
      prevTwoStairs = prevOneStair;
      prevOneStair = ans;
    }

    return ans;
  }
}