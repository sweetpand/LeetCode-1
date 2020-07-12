struct Elem {
  int i;
  int j;
};

class Solution {
 public:
  int trapRainWater(vector<vector<int>>& heightMap) {
    const int m = heightMap.size();
    const int n = heightMap[0].size();
    const vector<int> dirs{0, 1, 0, -1, 0};

    int ans = 0;
    int maxHeight = 0;
    auto compare = [&](const Elem& a, const Elem& b) {
      return heightMap[a.i][a.j] > heightMap[b.i][b.j];
    };
    priority_queue<Elem, vector<Elem>, decltype(compare)> pq(compare);
    vector<vector<bool>> seen(m, vector<bool>(n));

    for (int i = 0; i < m; ++i) {
      pq.push({i, 0});
      pq.push({i, n - 1});
      seen[i][0] = true;
      seen[i][n - 1] = true;
    }

    for (int j = 1; j < n - 1; ++j) {
      pq.push({0, j});
      pq.push({m - 1, j});
      seen[0][j] = true;
      seen[m - 1][j] = true;
    }

    while (!pq.empty()) {
      const auto [i, j] = pq.top(); pq.pop();
      maxHeight = max(maxHeight, heightMap[i][j]);
      for (int k = 0; k < 4; ++k) {
        const int x = i + dirs[k];
        const int y = j + dirs[k + 1];
        if (x < 0 || x == m || y < 0 || y == n) continue;
        if (seen[x][y]) continue;
        ans += max(maxHeight - heightMap[x][y], 0);
        pq.push({x, y});
        seen[x][y] = true;
      }
    }

    return ans;
  }
};