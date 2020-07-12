class Solution {
  public int minDepth(TreeNode root) {
    if (root == null)
      return 0;

    int ans = 0;
    Queue<TreeNode> queue = new LinkedList<>();
    queue.add(root);

    while (!queue.isEmpty()) {
      ++ans;
      for (int i = queue.size(); i > 0; --i) {
        TreeNode node = queue.poll();
        if (node.left == null && node.right == null)
          return ans;
        if (node.left != null)
          queue.add(node.left);
        if (node.right != null)
          queue.add(node.right);
      }
    }

    throw new IllegalArgumentException();
  }
}