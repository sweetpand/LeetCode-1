class Solution {
 public:
  int rob(vector<int>& nums) {
    int prev1 = 0;
    int prev2 = 0;

    for (const int num : nums) {
      const int cache = prev1;
      prev1 = max(prev1, prev2 + num);
      prev2 = cache;
    }

    return prev1;
  }
};