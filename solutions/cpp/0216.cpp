class Solution {
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans;
    vector<int> path;

    function<void(int, int, int)> dfs = [&](int s, int k, int n) {
      if (k == 0 && n == 0) {
        ans.push_back(path);
        return;
      }
      if (k == 0 || n <= 0) return;

      for (int i = s; i <= 9; ++i) {
        path.push_back(i);
        dfs(i + 1, k - 1, n - i);
        path.pop_back();
      }
    };

    dfs(1, k, n);

    return ans;
  }
};