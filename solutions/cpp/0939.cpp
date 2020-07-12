class Solution {
 public:
  int minAreaRect(vector<vector<int>>& points) {
    int ans = INT_MAX;
    unordered_map<int, unordered_set<int>> xToYs;

    for (vector<int>& point : points) xToYs[point[0]].insert(point[1]);

    for (int i = 0; i < points.size(); ++i)
      for (int j = 0; j < i; ++j) {
        if (points[i][0] == points[j][0] || points[i][1] == points[j][1])
          continue;
        if (xToYs[points[i][0]].count(points[j][1]) &&
            xToYs[points[j][0]].count(points[i][1]))
          ans = min(ans, abs(points[i][0] - points[j][0]) *
                             abs(points[i][1] - points[j][1]));
      }

    return ans < INT_MAX ? ans : 0;
  }
};