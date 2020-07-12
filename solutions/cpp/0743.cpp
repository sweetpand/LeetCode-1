class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<vector<pair<int, int>>> graph(N + 1);
    vector<int> seen(N + 1);

    for (const vector<int>& time : times)
      graph[time[0]].push_back({time[1], time[2]});

    auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.second > b.second;  // sorted by w (smallest in the top)
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)>
        pq(compare);

    pq.push({K, 0});
    int ans = 0;

    while (!pq.empty()) {
      const auto [u, dist] = pq.top(); pq.pop();
      if (seen[u]) continue;
      seen[u] = true;
      ans = dist;  // the minDist to go to current node u
      if (--N == 0) return ans;
      for (const auto& [v, w] : graph[u])
        pq.push({v, dist + w});
    }

    return -1;
  }
};