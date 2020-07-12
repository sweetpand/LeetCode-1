public class Codec {
  public String serialize(TreeNode root) {
    if (root == null)
      return "";

    StringBuilder ans = new StringBuilder();
    Queue<TreeNode> queue = new LinkedList<>();
    queue.add(root);

    while (!queue.isEmpty()) {
      TreeNode node = queue.poll();
      if (node == null) {
        ans.append("n ");
        continue;
      }
      ans.append(node.val + " ");
      queue.add(node.left);
      queue.add(node.right);
    }

    return ans.toString();
  }

  public TreeNode deserialize(String data) {
    if (data.equals(""))
      return null;

    String[] vals = data.split(" ");
    TreeNode root = new TreeNode(Integer.parseInt(vals[0]));
    Queue<TreeNode> queue = new LinkedList<>();
    queue.add(root);

    for (int i = 1; i < vals.length; ++i) {
      TreeNode parent = queue.poll();
      if (!vals[i].equals("n")) {
        TreeNode left = new TreeNode(Integer.parseInt(vals[i]));
        parent.left = left;
        queue.add(left);
      }
      if (!vals[++i].equals("n")) {
        TreeNode right = new TreeNode(Integer.parseInt(vals[i]));
        parent.right = right;
        queue.add(right);
      }
    }

    return root;
  }
}