class Solution {
 public:
  Solution(vector<int>& nums) : nums(move(nums)) {
    srand(time(nullptr));
  }

  vector<int> reset() {
    return nums;
  }

  vector<int> shuffle() {
    vector<int> A(nums);
    for (int i = A.size() - 1; i >= 0; --i) {
      int j = rand() % (i + 1);
      swap(A[i], A[j]);
    }
    return A;
  }

 private:
  vector<int> nums;
};