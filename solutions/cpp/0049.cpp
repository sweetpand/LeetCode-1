class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> map;

    for (const string& str : strs) {
      string s = str;
      sort(begin(s), end(s));
      map[s].push_back(str);
    }

    for (const auto& [_, value] : map)
      ans.push_back(value);

    return ans;
  }
};