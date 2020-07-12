class Solution {
  public List<Integer> inorderTraversal(TreeNode root) {
    List<Integer> ans = new ArrayList<>();
    TreeNode curr = root;

    while (curr != null) {
      if (curr.left == null) {
        ans.add(curr.val);
        curr = curr.right;
      } else {
        TreeNode prev = curr.left;
        while (prev.right != null)
          prev = prev.right;
        prev.right = curr;
        TreeNode temp = curr;
        curr = curr.left;
        temp.left = null;
      }
    }

    return ans;
  }
}