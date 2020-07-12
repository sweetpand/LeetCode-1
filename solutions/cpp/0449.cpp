class Codec {
 public:
  string serialize(TreeNode* root) {
    string ans;

    function<void(TreeNode*)> helper = [&](TreeNode* root) {
      if (!root) return;

      ans += to_string(root->val) + " ";
      helper(root->left);
      helper(root->right);
    };

    helper(root);

    return ans;
  }

  TreeNode* deserialize(string data) {
    istringstream iss(data);
    queue<int> q;

    for (string s; iss >> s;)
      q.push(stoi(s));

    function<TreeNode*(int, int)> helper = [&](int min, int max) -> TreeNode* {
      if (q.empty()) return nullptr;

      const int val = q.front();
      if (val < min || val > max) return nullptr;

      TreeNode* root = new TreeNode(val);
      q.pop();
      root->left = helper(min, val);
      root->right = helper(val, max);

      return root;
    };

    return helper(INT_MIN, INT_MAX);
  }
};