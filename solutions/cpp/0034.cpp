class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    const int leftIndex = find(nums, target, true);

    if (leftIndex == nums.size() || nums[leftIndex] != target) return {-1, -1};

    return {leftIndex, find(nums, target, false) - 1};
  }

 private:
  int find(vector<int>& nums, int target, bool isLeft) {
    int l = 0;
    int r = nums.size();

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (nums[m] > target || (isLeft && nums[m] == target))
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};