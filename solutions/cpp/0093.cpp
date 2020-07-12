class Solution {
 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> ans;
    vector<string> path;

    function<void(int)> dfs = [&](int index) {
      if (path.size() == 4 && index == s.length()) {
        ans.push_back(path[0] + "." + path[1] + "." + path[2] + "." + path[3]);
        return;
      }
      if (path.size() == 4 || index == s.length()) return;

      for (int i = 1; i <= 3; ++i) {
        if (index + i > s.length()) return;    // out of bound
        if (i > 1 && s[index] == '0') return;  // leading '0'
        const string num = s.substr(index, i);
        if (stoi(num) > 255) return;
        path.push_back(num);
        dfs(index + i);
        path.pop_back();
      }
    };

    dfs(0);

    return ans;
  }
};