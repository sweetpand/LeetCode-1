class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
    vector<vector<int>> ans;
    vector<vector<int>> events;

    for (const vector<int>& building : buildings) {
      events.push_back({building[0], building[2]});
      events.push_back({building[1], -building[2]});
    }

    sort(begin(events), end(events),
         [](const vector<int>& e1, const vector<int>& e2) {
           return e1[0] == e2[0] ? e1[1] > e2[1] : e1[0] < e2[0];
         });

    for (const vector<int>& event : events) {
      const int x = event[0];
      const int h = abs(event[1]);

      if (event[1] > 0) {
        if (h > maxHeight()) ans.push_back({x, h});
        set.insert(h);
      } else {
        set.erase(set.equal_range(h).first);
        if (h > maxHeight()) ans.push_back({x, maxHeight()});
      }
    }

    return ans;
  }

 private:
  multiset<int> set;
  int maxHeight() const { return set.empty() ? 0 : *rbegin(set); }
};