class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    int ans = 0;
    int degree = 0;
    unordered_map<int, int> firstSeen;
    unordered_map<int, int> numCounts;

    for (int i = 0; i < nums.size(); ++i) {
      if (!firstSeen.count(nums[i]))
        firstSeen[nums[i]] = i;
      ++numCounts[nums[i]];
      if (numCounts[nums[i]] > degree) {
        degree = numCounts[nums[i]];
        ans = i - firstSeen[nums[i]] + 1;
      } else if (numCounts[nums[i]] == degree)
        ans = min(ans, i - firstSeen[nums[i]] + 1);
    }

    return ans;
  }
};