class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode dummy(0);
    ListNode* curr = &dummy;
    auto compare = [](const ListNode* a, const ListNode* b) {
      return a->val > b->val;
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

    for (ListNode* list : lists)
      if (list)
        pq.push(list);

    while (!pq.empty()) {
      curr->next = pq.top(), pq.pop();
      curr = curr->next;
      if (curr->next) pq.push(curr->next);
    }

    return dummy.next;
  }
};