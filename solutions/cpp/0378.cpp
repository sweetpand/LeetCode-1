class Solution {
 public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    auto compare = [&](const pair<int, int>& a, const pair<int, int>& b) {
      return matrix[a.first][a.second] > matrix[b.first][b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>
        pq(compare);

    for (int i = 0; i < matrix.size() && i < k; ++i)
      pq.push({i, 0});

    while (k-- > 1) {
      const auto [i, j] = pq.top(); pq.pop();
      if (j + 1 < matrix.size())
        pq.push({i, j + 1});
    }

    return matrix[pq.top().first][pq.top().second];
  }
};