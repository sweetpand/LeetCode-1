class Solution {
 public:
  int maxRotateFunction(vector<int>& A) {
    const int sum = accumulate(begin(A), end(A), (long)0);
    int f = 0;

    for (int i = 0; i < A.size(); ++i)
      f += i * A[i];  // calculate F(0) first

    int ans = f;

    for (int i = A.size() - 1; i > 0; --i) {
      f += sum - A.size() * A[i];
      ans = max(ans, f);
    }

    return ans;
  }
};