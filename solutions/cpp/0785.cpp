class Solution {
 public:
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int> colors(graph.size());  // 1: red, -1: green

    for (int i = 0; i < graph.size(); ++i) {
      if (colors[i] != 0) continue;
      queue<int> q{{i}};
      colors[i] = 1;

      while (!q.empty()) {
        const int node = q.front(); q.pop();
        const int color = colors[node];
        for (const int neighbor : graph[node])
          if (colors[neighbor] == 0) {
            colors[neighbor] = -color;
            q.push(neighbor);
          } else if (colors[neighbor] != -color) {
            return false;
          }
      }
    }

    return true;
  }
};