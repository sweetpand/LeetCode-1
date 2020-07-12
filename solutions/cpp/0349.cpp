class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_set<int> nums1Set{begin(nums1), end(nums1)};

    for (const int num : nums2)
      if (nums1Set.erase(num))
        ans.push_back(num);

    return ans;
  }
};