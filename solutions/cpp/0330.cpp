class Solution {
 public:
  int minPatches(vector<int>& nums, int n) {
    int ans = 0;
    long minMissNum = 1;

    for (int i = 0; minMissNum <= n;)
      if (i < nums.size() && nums[i] <= minMissNum)
        minMissNum += nums[i++];
      else {
        minMissNum += minMissNum;  // greedily add itself
        ++ans;
      }

    return ans;
  }
};