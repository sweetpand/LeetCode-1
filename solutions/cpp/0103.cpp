class Solution {
 public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    if (!root) return {};

    vector<vector<int>> ans;
    deque<TreeNode*> deque{{root}};
    bool isLeftToRight = true;

    while (!deque.empty()) {
      vector<int> currLevel;
      for (int i = deque.size(); i > 0; --i)
        if (isLeftToRight) {
          root = deque.front(), deque.pop_front();
          currLevel.push_back(root->val);
          if (root->left) deque.push_back(root->left);
          if (root->right) deque.push_back(root->right);
        } else {
          root = deque.back(), deque.pop_back();
          currLevel.push_back(root->val);
          if (root->right) deque.push_front(root->right);
          if (root->left) deque.push_front(root->left);
        }
      ans.push_back(currLevel);
      isLeftToRight = !isLeftToRight;
    }

    return ans;
  }
};