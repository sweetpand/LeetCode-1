class RandomizedCollection {
 public:
  bool insert(int val) {
    map[val].push_back(vals.size());
    vals.emplace_back(val, map[val].size() - 1);
    return map[val].size() == 1;
  }

  bool remove(int val) {
    if (!map.count(val) || map[val].empty()) return false;
    int index = map[val].back();
    map[vals.back().first][vals.back().second] = index;
    map[val].pop_back();
    swap(vals[index], vals.back());
    vals.pop_back();
    return true;
  }

  int getRandom() {
    int index = rand() % vals.size();
    return vals[index].first;
  }

 private:
  vector<pair<int, int>> vals;
  unordered_map<int, vector<int>> map;
};