class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    int ans = 0;
    vector<int> dp(envelopes.size());

    sort(begin(envelopes), end(envelopes), [](const auto& a, const auto& b) {
      return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });

    for (const vector<int>& envelope : envelopes) {
      int l = 0;
      int r = ans;
      while (l < r) {
        const int m = l + (r - l) / 2;
        if (dp[m] < envelope[1])
          l = m + 1;
        else
          r = m;
      }
      dp[l] = envelope[1];
      if (l == ans) ++ans;
    }

    return ans;
  }
};