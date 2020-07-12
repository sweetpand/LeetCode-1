class Solution {
  public void nextPermutation(int[] nums) {
    int i;
    for (i = nums.length - 2; i >= 0; --i)
      if (nums[i] < nums[i + 1])
        break;

    if (i >= 0) {
      int j;
      for (j = nums.length - 1; j > i; --j)
        if (nums[j] > nums[i])
          break;
      swap(nums, i, j);
    }

    reverse(nums, i + 1, nums.length - 1);
  }

  private void reverse(int[] nums, int l, int r) {
    while (l < r)
      swap(nums, l++, r--);
  }

  private void swap(int[] nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
  }
}