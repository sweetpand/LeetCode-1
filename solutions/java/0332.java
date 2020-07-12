class Solution {
  public List<String> findItinerary(List<List<String>> tickets) {
    List<String> ans = new LinkedList<>();
    Map<String, PriorityQueue<String>> graph = new HashMap<>();

    for (final List<String> ticket : tickets)
      graph.computeIfAbsent(ticket.get(0), k -> new PriorityQueue<>()).add(ticket.get(1));

    dfs("JFK", graph, ans);

    return ans;
  }

  private void dfs(final String airport, Map<String, PriorityQueue<String>> graph, List<String> ans) {
    while (graph.containsKey(airport) && !graph.get(airport).isEmpty()) {
      String nextAirport = graph.get(airport).poll();
      dfs(nextAirport, graph, ans);
    }
    ans.add(0, airport);
  }
}