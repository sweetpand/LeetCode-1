class Solution {
  public List<List<Integer>> threeSum(int[] nums) {
    List<List<Integer>> ans = new ArrayList<>();

    Arrays.sort(nums);

    for (int i = 0; i + 2 < nums.length; ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int l = i + 1;
      int r = nums.length - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          ans.add(Arrays.asList(nums[i], nums[l], nums[r]));
          ++l;
          --r;
          while (nums[l] == nums[l - 1] && l < r)
            ++l;
          while (nums[r] == nums[r + 1] && l < r)
            --r;
        } else if (sum < 0) {
          ++l;
        } else {
          --r;
        }
      }
    }

    return ans;
  }
}