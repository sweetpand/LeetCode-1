class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> set{begin(nums), end(nums)};

    for (long num : nums)
      if (!set.count(num - 1)) {
        int length = 0;
        while (set.count(num++))
          ++length;
        ans = max(ans, length);
      }

    return ans;
  }
};