class Solution {
  public void recoverTree(TreeNode root) {
    inorder(root);
    int temp = x.val;
    x.val = y.val;
    y.val = temp;
  }

  private TreeNode x = null;
  private TreeNode y = null;
  private TreeNode pred = null;

  private void inorder(TreeNode root) {
    if (root == null)
      return;

    inorder(root.left);

    if (pred != null && pred.val > root.val) {
      y = root;
      if (x == null)
        x = pred;
      else
        return;
    }
    pred = root;

    inorder(root.right);
  }
}