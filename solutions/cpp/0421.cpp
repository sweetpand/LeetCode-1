class Solution {
 public:
  int findMaximumXOR(vector<int>& nums) {
    int ans = 0;
    int mask = 0;

    for (int i = 31; i >= 0; --i) {
      mask = mask | (1 << i);
      unordered_set<int> prefixes;
      for (const int num : nums)
        prefixes.insert(num & mask);
      const int candidate = ans | (1 << i);
      for (const int prefix : prefixes)
        if (prefixes.count(prefix ^ candidate)) {
          ans = candidate;
          break;
        }
    }

    return ans;
  }
};