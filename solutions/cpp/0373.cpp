class Solution {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                     int k) {
    if (nums2.empty()) return {};

    vector<vector<int>> ans;

    auto compare = [&](const pair<int, int>& a, const pair<int, int>& b) {
      return nums1[a.first] + nums2[a.second] >
             nums1[b.first] + nums2[b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>
        pq(compare);

    for (int i = 0; i < nums1.size() && i < k; ++i)
      pq.push({i, 0});

    while (!pq.empty() && ans.size() < k) {
      const auto [index1, index2] = pq.top(); pq.pop();
      ans.push_back({nums1[index1], nums2[index2]});
      if (index2 + 1 < nums2.size())
        pq.push({index1, index2 + 1});
    }

    return ans;
  }
};