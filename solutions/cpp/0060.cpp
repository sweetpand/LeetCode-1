class Solution {
 public:
  string getPermutation(int n, int k) {
    string ans;
    vector<int> nums(n);
    vector<int> factorial(n, 1);

    for (int i = 0; i < n; ++i)
      nums[i] = i + 1;

    for (int i = 1; i < n; ++i)
      factorial[i] = factorial[i - 1] * i;

    --k;

    for (int i = n; i >= 1; --i) {
      const int j = k / factorial[i - 1];
      k %= factorial[i - 1];
      ans.append(to_string(nums[j]));
      nums.erase(begin(nums) + j);
    }

    return ans;
  }
};