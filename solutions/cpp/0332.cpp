class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    deque<string> ans;
    map<string, multiset<string>> graph;

    for (const vector<string>& ticket : tickets)
      graph[ticket[0]].insert(ticket[1]);

    function<void(const string&)> dfs = [&](const string& airport) {
      while (graph.count(airport) && !graph[airport].empty()) {
        const string nextAirport = *begin(graph[airport]);
        graph[airport].erase(begin(graph[airport]));
        dfs(nextAirport);
      }
      ans.push_front(airport);
    };

    dfs("JFK");

    return {begin(ans), end(ans)};
  }
};