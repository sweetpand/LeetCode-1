class Solution {
  public ListNode swapPairs(ListNode head) {
    ListNode dummy = new ListNode(0);
    dummy.next = head;
    int length = 0;
    for (ListNode curr = head; curr != null; curr = curr.next)
      ++length;

    ListNode prev = dummy;
    ListNode curr = head;

    for (int i = 0; i < length / 2; ++i) {
      ListNode next = curr.next;
      curr.next = next.next;
      next.next = curr;
      prev.next = next;
      prev = curr;
      curr = curr.next;
    }

    return dummy.next;
  }
}