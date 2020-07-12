class Solution {
  public ListNode mergeKLists(ListNode[] lists) {
    ListNode dummy = new ListNode(0);
    ListNode curr = dummy;
    Queue<ListNode> pq = new PriorityQueue<>((l1, l2) -> l1.val - l2.val);

    for (ListNode list : lists)
      if (list != null)
        pq.add(list);

    while (!pq.isEmpty()) {
      curr.next = pq.poll();
      curr = curr.next;
      if (curr.next != null)
        pq.add(curr.next);
    }

    return dummy.next;
  }
}