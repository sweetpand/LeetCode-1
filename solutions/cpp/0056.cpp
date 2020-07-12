class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;

    sort(begin(intervals), end(intervals),
         [](const auto& a, const auto& b) { return a[0] < b[0]; });

    for (const vector<int>& interval : intervals)
      if (ans.empty() || interval[0] > ans.back()[1])
        ans.push_back(interval);
      else
        ans.back()[1] = max(ans.back()[1], interval[1]);

    return ans;
  }
};