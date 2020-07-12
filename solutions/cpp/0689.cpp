class Solution {
 public:
  vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    const int n = nums.size();
    const int m = n - k + 1;

    vector<int> sums(m);   // sums[i] := sum(nums[i..i + k))
    vector<int> left(m);   // left[i] := index in [0..i] having max sums[i]
    vector<int> right(m);  // right[i] := index in [i..m - 1] having max sums[i]

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += nums[i];
      if (i >= k) sum -= nums[i - k];
      if (i >= k - 1) sums[i - k + 1] = sum;
    }

    int maxIndex = 0;
    for (int i = 0; i < m; ++i) {
      if (sums[i] > sums[maxIndex])
        maxIndex = i;
      left[i] = maxIndex;
    }

    maxIndex = m - 1;
    for (int i = m - 1; i >= 0; --i) {
      if (sums[i] >= sums[maxIndex])
        maxIndex = i;
      right[i] = maxIndex;
    }

    vector<int> ans{-1, -1, -1};

    for (int i = k; i < m - k; ++i)
      if (ans[0] == -1 ||
          sums[ans[0]] + sums[ans[1]] + sums[ans[2]] <
              sums[left[i - k]] + sums[i] + sums[right[i + k]]) {
        ans[0] = left[i - k];
        ans[1] = i;
        ans[2] = right[i + k];
      }

    return ans;
  }
};