class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    const int sum = accumulate(begin(nums), end(nums), 0);

    if (sum & 1) return false;

    vector<bool> dp(sum / 2 + 1);
    dp[0] = true;

    for (const int num : nums)
      for (int w = sum / 2; w >= num; --w)
        dp[w] = dp[w] || dp[w - num];

    return dp[sum / 2];
  }
};