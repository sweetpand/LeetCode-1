class Solution {
  public boolean canPartition(int[] nums) {
    final int sum = Arrays.stream(nums).sum();

    if (sum % 2 == 1)
      return false;

    boolean[] dp = new boolean[sum / 2 + 1];
    dp[0] = true;

    for (int num : nums)
      for (int w = sum / 2; w >= num; --w)
        dp[w] = dp[w] || dp[w - num];

    return dp[sum / 2];
  }
}