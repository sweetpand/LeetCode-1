class Solution {
 public:
  bool isMonotonic(vector<int>& A) {
    bool increasing = true;
    bool decreasing = true;

    for (int i = 1; i < A.size(); ++i) {
      increasing &= A[i - 1] <= A[i];
      decreasing &= A[i - 1] >= A[i];
    }

    return increasing || decreasing;
  }
};