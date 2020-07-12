class Codec {
 public:
  string serialize(TreeNode* root) {
    string ans;

    function<void(TreeNode*)> helper = [&](TreeNode* root) {
      if (!root) {
        ans += "# ";
        return;
      }

      ans += to_string(root->val) + " ";
      helper(root->left);
      helper(root->right);
    };

    helper(root);

    return ans;
  }

  TreeNode* deserialize(string data) {
    istringstream iss(data);
    queue<string> q;

    for (string s; iss >> s;)
      q.push(s);

    function<TreeNode*()> helper = [&]() -> TreeNode* {
      const string s = q.front(); q.pop();
      if (s == "#") return nullptr;

      TreeNode* root = new TreeNode(stoi(s));
      root->left = helper();
      root->right = helper();

      return root;
    };

    return helper();
  }
};