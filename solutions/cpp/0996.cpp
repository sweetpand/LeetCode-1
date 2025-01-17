class Solution {
 public:
  int numSquarefulPerms(vector<int>& A) {
    int ans = 0;
    vector<int> path;
    vector<bool> used(A.size(), false);

    sort(begin(A), end(A));
    dfs(A, used, path, ans);

    return ans;
  }

 private:
  void dfs(vector<int>& A, vector<bool>& used, vector<int>& path, int& ans) {
    if (path.size() > 1 && !isSquare(path.back() + path[path.size() - 2]))
      return;
    if (path.size() == A.size()) {
      ++ans;
      return;
    }

    for (int i = 0; i < A.size(); ++i) {
      if (used[i]) continue;
      if (i > 0 && A[i] == A[i - 1] && !used[i - 1]) continue;
      used[i] = true;
      path.push_back(A[i]);
      dfs(A, used, path, ans);
      path.pop_back();
      used[i] = false;
    }
  }

  bool isSquare(int num) {
    int root = sqrt(num);
    return root * root == num;
  }
};