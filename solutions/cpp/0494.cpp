class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    const int sum = accumulate(begin(nums), end(nums), 0);
    if (sum < S || (sum + S) & 1) return 0;

    function<int(int)> subsetSum = [&](int target) {
      vector<int> dp(target + 1);
      dp[0] = 1;

      for (const int num : nums)
        for (int w = target; w >= num; --w)
          dp[w] += dp[w - num];

      return dp[target];
    };

    return subsetSum((sum + S) / 2);
  }
};