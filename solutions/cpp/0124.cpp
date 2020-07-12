class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;

    function<int(TreeNode*)> maxPathSumDownFrom = [&](TreeNode* root) {
      if (!root) return 0;

      const int left = max(maxPathSumDownFrom(root->left), 0);
      const int right = max(maxPathSumDownFrom(root->right), 0);
      ans = max(ans, root->val + left + right);

      return root->val + max(left, right);
    };

    maxPathSumDownFrom(root);

    return ans;
  }
};