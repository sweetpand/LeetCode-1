class Solution {
  public int maxProduct(int[] nums) {
    int ans = nums[0];
    int prevMin = nums[0];
    int prevMax = nums[0];

    for (int i = 1; i < nums.length; ++i) {
      int min = prevMin * nums[i];
      int max = prevMax * nums[i];
      prevMin = Math.min(nums[i], Math.min(min, max));
      prevMax = Math.max(nums[i], Math.max(min, max));
      ans = Math.max(ans, prevMax);
    }

    return ans;
  }
}