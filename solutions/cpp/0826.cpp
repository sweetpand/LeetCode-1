class Solution {
 public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit,
                          vector<int>& worker) {
    int ans = 0;
    vector<pair<int, int>> jobs;

    for (int i = 0; i < difficulty.size(); ++i)
      jobs.push_back({difficulty[i], profit[i]});

    sort(begin(jobs), end(jobs));
    sort(begin(worker), end(worker));

    int i = 0;
    int maxProfit = 0;

    for (int w : worker) {
      for (; i < jobs.size() && w >= jobs[i].first; ++i)
        maxProfit = max(maxProfit, jobs[i].second);
      ans += maxProfit;
    }

    return ans;
  }
};