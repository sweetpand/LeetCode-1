class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    int ans = 0;

    for (int i = 0; i < points.size(); ++i) {
      map<pair<int, int>, int> count;
      vector<int> p1{points[i]};
      int samePoints = 1;
      int maxPoints = 0;
      for (int j = i + 1; j < points.size(); ++j) {
        vector<int> p2{points[j]};
        if (p1 == p2)
          ++samePoints;
        else
          maxPoints = max(maxPoints, ++count[getSlope(p1, p2)]);
      }
      ans = max(ans, samePoints + maxPoints);
    }

    return ans;
  }

 private:
  pair<int, int> getSlope(vector<int>& p1, vector<int>& p2) {
    const int dx = p2[0] - p1[0];
    const int dy = p2[1] - p1[1];

    if (dx == 0) return {0, p1[0]};
    if (dy == 0) return {p1[1], 0};

    const int d = __gcd(dx, dy);

    return {dx / d, dy / d};
  }
};