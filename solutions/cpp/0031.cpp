class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int i;
    for (i = nums.size() - 2; i >= 0; --i)
      if (nums[i] < nums[i + 1]) break;

    if (i >= 0) {
      int j;
      for (j = nums.size() - 1; j > i; --j)
        if (nums[j] > nums[i]) break;
      swap(nums[i], nums[j]);
    }

    reverse(nums, i + 1, nums.size() - 1);
  }

 private:
  void reverse(vector<int>& nums, int l, int r) {
    while (l < r) swap(nums[l++], nums[r--]);
  }
};