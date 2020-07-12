class Solution {
 public:
  void recoverTree(TreeNode* root) {
    vector<int> nums;

    inorder(root, nums);
    findTwoSwappedNums(nums);
    recover(root);
  }

 private:
  int x = -1;
  int y = -1;

  void inorder(TreeNode* root, vector<int>& nums) {
    if (!root) return;

    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
  }

  void findTwoSwappedNums(vector<int>& nums) {
    for (int i = 0; i + 1 < nums.size(); ++i)
      if (nums[i] > nums[i + 1]) {
        y = nums[i + 1];
        if (x == -1)
          x = nums[i];
        else
          break;
      }
  }

  void recover(TreeNode* root) {
    if (!root) return;
    if (root->val == x)
      root->val = y;
    else if (root->val == y)
      root->val = x;

    recover(root->left);
    recover(root->right);
  }
};