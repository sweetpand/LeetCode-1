class Solution {
  public int minSubArrayLen(int s, int[] nums) {
    int ans = Integer.MAX_VALUE;
    int sum = 0;

    for (int i = 0, j = 0; i < nums.length; ++i) {
      sum += nums[i];
      while (sum >= s) {
        ans = Math.min(ans, i - j + 1);
        sum -= nums[j++];
      }
    }

    return ans != Integer.MAX_VALUE ? ans : 0;
  }
}