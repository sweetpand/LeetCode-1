class Solution {
  public ListNode reverseBetween(ListNode head, int m, int n) {
    if (head == null)
      return null;

    ListNode prev = null;
    ListNode curr = head;

    for (int i = 0; i < m - 1; ++i) {
      prev = curr;
      curr = curr.next;
    }

    ListNode conn = prev;
    ListNode tail = curr;

    for (int i = 0; i < n - m + 1; ++i) {
      ListNode next = curr.next;
      curr.next = prev;
      prev = curr;
      curr = next;
    }

    if (conn != null)
      conn.next = prev;
    else
      head = prev;
    tail.next = curr;

    return head;
  }
}