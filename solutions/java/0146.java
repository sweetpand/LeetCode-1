class LRUCache {
  public LRUCache(int capacity) {
    this.capacity = capacity;
    join(head, tail);
  }

  public int get(int key) {
    if (!map.containsKey(key))
      return -1;

    Node node = map.get(key);
    remove(node);
    moveToHead(node);
    return node.value;
  }

  public void put(int key, int value) {
    if (map.containsKey(key)) {
      Node node = map.get(key);
      node.value = value;
      remove(node);
      moveToHead(node);
      return;
    }

    if (map.size() == capacity) {
      Node lastNode = tail.prev;
      map.remove(lastNode.key);
      remove(lastNode);
    }

    moveToHead(new Node(key, value));
    map.put(key, head.next);
  }

  private void join(Node node1, Node node2) {
    node1.next = node2;
    node2.prev = node1;
  }

  private void remove(Node node) {
    join(node.prev, node.next);
  }

  private void moveToHead(Node node) {
    join(node, head.next);
    join(head, node);
  }

  private int capacity;
  private Map<Integer, Node> map = new HashMap<>();
  private Node head = new Node(-1, -1);
  private Node tail = new Node(-1, -1);

  private class Node {
    Node prev;
    Node next;
    int key;
    int value;

    public Node(int key, int value) {
      this.key = key;
      this.value = value;
    }
  }
}