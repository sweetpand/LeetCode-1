class SummaryRanges {
 public:
  void addNum(int val) {
    if (map.count(val)) return;

    const int lo = lowerKey(val);
    const int hi = higherKey(val);

    if (lo >= 0 && hi >= 0 && map[lo][1] + 1 == val && hi == val + 1) {
      map[lo][1] = map[hi][1];
      map.erase(hi);
    } else if (lo >= 0 && map[lo][1] + 1 >= val) {
      map[lo][1] = max(map[lo][1], val);
    } else if (hi >= 0 && hi == val + 1) {
      map[val] = {val, map[hi][1]};
      map.erase(hi);
    } else {
      map[val] = {val, val};
    }
  }

  vector<vector<int>> getIntervals() {
    vector<vector<int>> ans;
    for (const auto& [_, intervals] : map)
      ans.push_back(intervals);
    return ans;
  }

 private:
  map<int, vector<int>> map;

  int lowerKey(int key) {
    auto it = map.lower_bound(key);
    if (it == begin(map)) return -1;
    return (--it)->first;
  }

  int higherKey(int key) {
    auto it = map.upper_bound(key);
    if (it == end(map)) return -1;
    return it->first;
  }
};