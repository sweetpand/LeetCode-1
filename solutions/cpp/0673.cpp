class Solution {
 public:
  int findNumberOfLIS(vector<int>& nums) {
    const int n = nums.size();

    int ans = 0;
    int maxLength = 0;

    vector<int> length(n, 1);  // length[i] := len of the LIS ending w/ nums[i]
    vector<int> count(n, 1);   // count[i] := # of the LIS ending w/ nums[i]

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j)
        if (nums[j] < nums[i]) {
          if (length[i] == length[j] + 1)
            count[i] += count[j];
          else if (length[i] < length[j] + 1) {
            length[i] = length[j] + 1;
            count[i] = count[j];
          }
        }
      if (maxLength == length[i])
        ans += count[i];
      else if (maxLength < length[i]) {
        maxLength = length[i];
        ans = count[i];
      }
    }

    return ans;
  }
};