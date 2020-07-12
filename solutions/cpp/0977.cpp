class Solution {
 public:
  vector<int> sortedSquares(vector<int>& A) {
    vector<int> ans(A.size());

    int i = A.size() - 1;
    for (int l = 0, r = A.size() - 1; l <= r;)
      if (abs(A[l]) > abs(A[r]))
        ans[i--] = A[l] * A[l++];
      else
        ans[i--] = A[r] * A[r--];

    return ans;
  }
};