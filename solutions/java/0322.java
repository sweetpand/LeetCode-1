class Solution {
  public int coinChange(int[] coins, int amount) {
    int[] dp = new int[amount + 1];
    Arrays.fill(dp, 1, dp.length, amount + 1);

    for (int i = 1; i < amount + 1; ++i)
      for (int coin : coins)
        if (coin <= i)
          dp[i] = Math.min(dp[i], dp[i - coin] + 1);

    return dp[amount] < amount + 1 ? dp[amount] : -1;
  }
}