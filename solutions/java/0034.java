class Solution {
  public int[] searchRange(int[] nums, int target) {
    int leftIndex = find(nums, target, true);

    if (leftIndex == nums.length || nums[leftIndex] != target)
      return new int[] { -1, -1 };

    return new int[] { leftIndex, find(nums, target, false) -1 };
  }

  private int find(int[] nums, int target, boolean isLeft) {
    int l = 0;
    int r = nums.length;

    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] > target || (isLeft && nums[m] == target))
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
}