class Solution {
 public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries) {
    vector<double> ans;
    unordered_map<string, unordered_map<string, double>> graph;

    for (int i = 0; i < equations.size(); ++i) {
      const string& a = equations[i][0];
      const string& b = equations[i][1];
      const double value = values[i];
      // construct the graph
      graph[a][b] = value;
      graph[b][a] = 1 / value;
    }

    function<double(const string&, const string&, unordered_set<string>&)> dfs =
        [&](const string& a, const string& c, unordered_set<string>& seen) {
          if (seen.count(a)) return -1.0;
          if (!graph.count(a) || !graph.count(c)) return -1.0;
          if (graph.count(a) && graph[a].count(c)) return graph[a][c];
          if (a == c) return 1.0;

          seen.insert(a);

          for (const auto& [neighbor, value] : graph[a]) {
            double res = dfs(neighbor, c, seen);
            if (res > 0) return value * res;
          }

          return -1.0;  // the answer doesn't exist
        };

    for (const vector<string>& query : queries) {
      const string& a = query[0];
      const string& c = query[1];
      unordered_set<string> seen;
      ans.push_back(dfs(a, c, seen));
    }

    return ans;
  }
};