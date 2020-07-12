class BSTIterator {
 public:
  BSTIterator(TreeNode* root) {
    while (root) {
      stack.push(root);
      root = root->left;
    }
  }

  int next() {
    TreeNode* node = stack.top(); stack.pop();

    const int res = node->val;
    node = node->right;
    while (node) {
      stack.push(node);
      node = node->left;
    }

    return res;
  }

  bool hasNext() {
    return !stack.empty();
  }

 private:
  stack<TreeNode*> stack;
};