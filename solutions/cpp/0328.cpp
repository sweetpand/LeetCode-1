class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    ListNode oddHead(0);
    ListNode evenHead(0);
    ListNode* odd = &oddHead;
    ListNode* even = &evenHead;

    for (int isOdd = 0; head; head = head->next)
      if (isOdd ^= 1) {
        odd->next = head;
        odd = head;
      } else {
        even->next = head;
        even = head;
      }

    even->next = nullptr;
    odd->next = evenHead.next;

    return oddHead.next;
  }
};