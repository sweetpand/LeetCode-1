class Solution {
  public boolean isSymmetric(TreeNode root) {
    return helper(root, root);
  }

  private boolean helper(TreeNode p, TreeNode q) {
    if (p == null || q == null)
      return p == q;

    return p.val == q.val && helper(p.left, q.right) && helper(p.right, q.left);
  }
}