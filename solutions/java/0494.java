class Solution {
  public int findTargetSumWays(int[] nums, int S) {
    final int sum = Arrays.stream(nums).sum();

    if (sum < S || (sum + S) % 2 == 1)
      return 0;

    return subsetSum(nums, (sum + S) / 2);
  }

  private int subsetSum(int[] nums, int s) {
    int[] dp = new int[s + 1];
    dp[0] = 1;

    for (int num : nums)
      for (int w = s; w >= num; --w)
        dp[w] += dp[w - num];

    return dp[s];
  }
}