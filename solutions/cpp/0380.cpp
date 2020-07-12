class RandomizedSet {
 public:
  bool insert(int val) {
    if (map.count(val)) return false;
    map[val] = vals.size();
    vals.push_back(val);
    return true;
  }

  bool remove(int val) {
    if (!map.count(val)) return false;
    int index = map[val];
    map[vals.back()] = index;
    map.erase(val);
    swap(vals[index], vals.back());
    vals.pop_back();
    return true;
  }

  int getRandom() {
    int index = rand() % vals.size();
    return vals[index];
  }

 private:
  vector<int> vals;
  unordered_map<int, int> map;
};