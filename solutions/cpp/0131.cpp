class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> path;

    auto isPalindrome = [](const string& s, int l, int r) {
      while (l < r)
        if (s[l++] != s[r--])
          return false;
      return true;
    };

    function<void(int)> dfs = [&](int startIndex) {
      if (startIndex == s.length()) {
        ans.push_back(path);
        return;
      }

      for (int i = startIndex; i < s.length(); ++i)
        if (isPalindrome(s, startIndex, i)) {
          path.push_back(s.substr(startIndex, i - startIndex + 1));
          dfs(i + 1);
          path.pop_back();
        }
    };

    dfs(0);

    return ans;
  }
};