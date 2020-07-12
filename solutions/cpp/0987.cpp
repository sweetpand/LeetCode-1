class Solution {
 public:
  vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> ans;
    map<int, vector<pair<int, int>>> xToNodes;

    dfs(root, 0, 0, xToNodes);

    for (auto&& [_, nodes] : xToNodes) {
      sort(begin(nodes), end(nodes));
      vector<int> vals;
      for (pair<int, int>& node : nodes) vals.push_back(node.second);
      ans.push_back(vals);
    }

    return ans;
  }

 private:
  void dfs(TreeNode* root, int x, int y,
           map<int, vector<pair<int, int>>>& xToNodes) {
    if (!root) return;

    xToNodes[x].push_back(pair<int, int>(-y, root->val));
    dfs(root->left, x - 1, y - 1, xToNodes);
    dfs(root->right, x + 1, y - 1, xToNodes);
  }
};