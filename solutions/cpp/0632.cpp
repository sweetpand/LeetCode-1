struct Item {
  int i;
  int j;
};

class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>>& nums) {
    auto compare = [&](const Item& a, const Item& b) {
      return nums[a.i][a.j] > nums[b.i][b.j];
    };
    priority_queue<Item, vector<Item>, decltype(compare)> pq(compare);

    int maxi = INT_MIN;
    for (int i = 0; i < nums.size(); ++i) {
      pq.push({i, 0});
      maxi = max(maxi, nums[i][0]);
    }
    int mini = nums[pq.top().i][pq.top().j];
    int ansMin = mini;
    int ansMax = maxi;

    while (pq.size() == nums.size()) {
      const auto [i, j] = pq.top(); pq.pop();
      if (j + 1 < nums[i].size()) {
        pq.push({i, j + 1});
        maxi = max(maxi, nums[i][j + 1]);
        mini = nums[pq.top().i][pq.top().j];
        if (maxi - mini < ansMax - ansMin) {
          ansMin = mini;
          ansMax = maxi;
        }
      }
    }

    return {ansMin, ansMax};
  }
};