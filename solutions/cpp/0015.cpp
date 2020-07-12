class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;

    sort(begin(nums), end(nums));

    for (int i = 0; i + 2 < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;

      int l = i + 1;
      int r = nums.size() - 1;
      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];
        if (sum == 0) {
          ans.push_back({nums[i], nums[l], nums[r]});
          ++l;
          --r;
          while (nums[l] == nums[l - 1] && l < r) ++l;
          while (nums[r] == nums[r + 1] && l < r) --r;
        } else if (sum < 0) {
          ++l;
        } else {
          --r;
        }
      }
    }

    return ans;
  }
};