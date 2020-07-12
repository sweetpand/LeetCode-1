class Solution {
  public Node copyRandomList(Node head) {
    if (head == null)
      return null;
    if (map.containsKey(head))
      return map.get(head);

    map.put(head, new Node(head.val));
    map.get(head).next = copyRandomList(head.next);
    map.get(head).random = copyRandomList(head.random);

    return map.get(head);
  }

  private Map<Node, Node> map = new HashMap<>();
}