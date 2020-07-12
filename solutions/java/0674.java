class Solution {
  public int findLengthOfLCIS(int[] nums) {
    int ans = 0;

    for (int i = 0, j = 0; i < nums.length; ++i) {
      if (i > 0 && nums[i] <= nums[i - 1])
        j = i;
      ans = Math.max(ans, i - j + 1);
    }

    return ans;
  }
}