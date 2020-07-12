class Solution {
 public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    const int n = nums.size();

    vector<int> ans;
    vector<int> lengthEndsAt(n, 1);
    vector<int> prevIndex(n, -1);
    int maxLength = 0;
    int index = -1;

    sort(begin(nums), end(nums));

    for (int i = 0; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j)
        if (nums[i] % nums[j] == 0 && lengthEndsAt[i] < lengthEndsAt[j] + 1) {
          lengthEndsAt[i] = lengthEndsAt[j] + 1;
          prevIndex[i] = j;
        }
      if (lengthEndsAt[i] > maxLength) {
        maxLength = lengthEndsAt[i];
        index = i;
      }
    }

    while (index != -1) {
      ans.push_back(nums[index]);
      index = prevIndex[index];
    }

    return ans;
  }
};