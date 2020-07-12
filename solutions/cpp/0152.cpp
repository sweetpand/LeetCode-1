class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int ans = nums[0];
    int currMin = nums[0];
    int currMax = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      const int a = currMin * nums[i];
      const int b = currMax * nums[i];
      currMin = min({a, b, nums[i]});
      currMax = max({a, b, nums[i]});
      ans = max(ans, currMax);
    }

    return ans;
  }
};