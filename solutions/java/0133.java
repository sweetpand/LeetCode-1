class Solution {
  public Node cloneGraph(Node node) {
    if (node == null)
      return null;
    if (map.containsKey(node))
      return map.get(node);

    map.put(node, new Node(node.val));
    for (Node neighbor : node.neighbors)
      map.get(node).neighbors.add(cloneGraph(neighbor));

    return map.get(node);
  }

  private Map<Node, Node> map = new HashMap<>();
}