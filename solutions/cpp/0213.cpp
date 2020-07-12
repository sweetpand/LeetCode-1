class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    if (nums.size() == 1) return nums[0];

    auto rob = [&](int l, int r) {
      int prev1 = 0;
      int prev2 = 0;

      for (int i = l; i <= r; ++i) {
        const int cache = prev1;
        prev1 = max(prev1, prev2 + nums[i]);
        prev2 = cache;
      }

      return prev1;
    };

    return max(rob(0, nums.size() - 2), rob(1, nums.size() - 1));
  }
};