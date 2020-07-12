class Solution {
 public:
  int sumNumbers(TreeNode* root) {
    int ans = 0;

    function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int path) {
      if (!root) return;
      if (!root->left && !root->right) {
        ans += path * 10 + root->val;
        return;
      }

      dfs(root->left, path * 10 + root->val);
      dfs(root->right, path * 10 + root->val);
    };

    dfs(root, 0);

    return ans;
  }
};