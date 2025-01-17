class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> path;

    function<void(int, int)> dfs = [&](int target, int s) {
      if (target < 0) return;
      if (target == 0) {
        ans.push_back(path);
        return;
      }

      for (int i = s; i < candidates.size(); ++i) {
        path.push_back(candidates[i]);
        dfs(target - candidates[i], i);
        path.pop_back();
      }
    };

    sort(begin(candidates), end(candidates));
    dfs(target, 0);

    return ans;
  }
};