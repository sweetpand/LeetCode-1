class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    if (map.count(head)) return map[head];

    map[head] = new Node(head->val);
    map[head]->next = copyRandomList(head->next);
    map[head]->random = copyRandomList(head->random);

    return map[head];
  }

 private:
  unordered_map<Node*, Node*> map;
};