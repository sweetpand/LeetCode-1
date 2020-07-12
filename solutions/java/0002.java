class Solution {
  public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    ListNode dummy = new ListNode(0);
    ListNode curr = dummy;
    int carry = 0;

    while (carry > 0 || l1 != null || l2 != null) {
      carry += (l1 == null ? 0 : l1.val) + (l2 == null ? 0 : l2.val);
      curr.next = new ListNode(carry % 10);
      curr = curr.next;
      carry /= 10;
      if (l1 != null)
        l1 = l1.next;
      if (l2 != null)
        l2 = l2.next;
    }

    return dummy.next;
  }
}