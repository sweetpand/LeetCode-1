class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head || m == n) return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode* prev = &dummy;

    for (int i = 0; i < m - 1; ++i)
      prev = prev->next;
    ListNode* tail = prev->next;

    for (int i = 0; i < n - m; ++i) {
      ListNode* cache = prev->next;
      prev->next = tail->next;
      tail->next = tail->next->next;
      prev->next->next = cache;
    }

    return dummy.next;
  }
};