class Solution {
 public:
  int rob(TreeNode* root) {
    const auto& [robRoot, notRobRoot] = robOrNot(root);

    return max(robRoot, notRobRoot);
  }

 private:
  pair<int, int> robOrNot(TreeNode* root) {
    if (!root) return {0, 0};

    const auto& [robLeft, notRobLeft] = robOrNot(root->left);
    const auto& [robRight, notRobRight] = robOrNot(root->right);

    return {root->val + notRobLeft + notRobRight,
            max(robLeft, notRobLeft) + max(robRight, notRobRight)};
  }
};