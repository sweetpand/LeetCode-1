class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> path;

    sort(begin(nums), end(nums));
    nSum(nums, target, 0, nums.size() - 1, 4, path, ans);

    return ans;
  }

 private:
  void nSum(vector<int>& nums, int target, int l, int r, int n,
            vector<int>& path, vector<vector<int>>& ans) {
    if (r - l + 1 < n || n < 2 || target < nums[l] * n || target > nums[r] * n)
      return;
    if (n == 2) {
      while (l < r) {
        int sum = nums[l] + nums[r];
        if (sum == target) {
          path.push_back(nums[l]);
          path.push_back(nums[r]);
          ans.push_back(path);
          path.pop_back();
          path.pop_back();
          ++l;
          while (nums[l] == nums[l - 1] && l < r) ++l;
        } else if (sum < target) {
          ++l;
        } else {
          --r;
        }
      }
      return;
    }

    for (int i = l; i <= r; ++i) {
      if (i > l && nums[i] == nums[i - 1]) continue;

      path.push_back(nums[i]);
      nSum(nums, target - nums[i], i + 1, r, n - 1, path, ans);
      path.pop_back();
    }
  }
};