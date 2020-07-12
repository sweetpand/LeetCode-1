class Solution {
  public int rob(TreeNode root) {
    int[] ans = helper(root);

    return Math.max(ans[0], ans[1]);
  }

  private int[] helper(TreeNode root) {
    if (root == null)
      return new int[2];

    int[] robLeft = helper(root.left);
    int[] robRight = helper(root.right);

    return new int[] { root.val + robLeft[1] + robRight[1],
        Math.max(robLeft[0], robLeft[1]) + Math.max(robRight[0], robRight[1]) };
  }
}