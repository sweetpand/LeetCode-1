class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    int ans = 0;
    long arrowX = (long)INT_MIN - 1;

    sort(begin(points), end(points),
         [](const auto& a, const auto& b) { return a[1] < b[1]; });

    for (const vector<int>& point : points)
      if (point[0] > arrowX) {
        ++ans;
        arrowX = point[1];
      }

    return ans;
  }
};