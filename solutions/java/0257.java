class Solution {
  public List<String> binaryTreePaths(TreeNode root) {
    List<String> ans = new ArrayList<>();

    dfs(root, "", ans);

    return ans;
  }

  private void dfs(TreeNode root, String path, List<String> ans) {
    if (root == null)
      return;
    if (root.left == null && root.right == null) {
      ans.add(path + String.valueOf(root.val));
      return;
    }

    dfs(root.left, path + String.valueOf(root.val) + "->", ans);
    dfs(root.right, path + String.valueOf(root.val) + "->", ans);
  }
}