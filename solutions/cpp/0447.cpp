class Solution {
 public:
  int numberOfBoomerangs(vector<vector<int>>& points) {
    int ans = 0;

    auto getDistance = [](const vector<int>& p, const vector<int>& q) {
      return pow(p[0] - q[0], 2) + pow(p[1] - q[1], 2);
    };

    for (const vector<int>& p : points) {
      unordered_map<int, int> distCount;
      for (const vector<int>& q : points) {
        const int dist = getDistance(p, q);
        ++distCount[dist];
      }
      for (const auto& [_, freq] : distCount)
        ans += freq * (freq - 1);  // C(freq, 2)
    }

    return ans;
  }
};