class Solution {
  public int maxPathSum(TreeNode root) {
    maxPathSumDownFrom(root);

    return ans;
  }

  private int ans = Integer.MIN_VALUE;

  private int maxPathSumDownFrom(TreeNode root) {
    if (root == null)
      return 0;

    int left = Math.max(maxPathSumDownFrom(root.left), 0);
    int right = Math.max(maxPathSumDownFrom(root.right), 0);
    ans = Math.max(ans, root.val + left + right);

    return root.val + Math.max(left, right);
  }
}