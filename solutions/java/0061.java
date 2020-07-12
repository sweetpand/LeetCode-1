class Solution {
  public ListNode rotateRight(ListNode head, int k) {
    if (head == null || head.next == null || k == 0)
      return head;

    int length = 0;
    for (ListNode curr = head; curr != null; curr = curr.next)
      ++length;

    k %= length;
    if (k == 0)
      return head;

    ListNode slow = head;
    ListNode fast = head;

    while (k-- > 0)
      fast = fast.next;

    while (fast != null && fast.next != null) {
      slow = slow.next;
      fast = fast.next;
    }

    ListNode ans = slow.next;
    slow.next = null;
    fast.next = head;

    return ans;
  }
}