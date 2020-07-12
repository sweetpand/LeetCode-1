class Solution {
 public:
  vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    int l = 0;
    int r = 0;

    // calculate how many '(' and ')' we have to delete
    for (const char c : s)
      if (c == '(')
        ++l;
      else if (c == ')') {
        if (l == 0)
          ++r;
        else
          --l;
      }

    dfs(s, 0, l, r, ans);

    return ans;
  }

 private:
  // check if `s` is a valid string
  bool isValid(const string& s) {
    int count = 0;  // num('(') - num(')')
    for (const char c : s) {
      if (c == '(')
        ++count;
      else if (c == ')')
        --count;
      if (count < 0) return false;
    }
    return true;  // return count == 0 is okay, too;
  }

  void dfs(const string& s, int startIndex, int l, int r, vector<string>& ans) {
    if (l == 0 && r == 0 && isValid(s)) {
      ans.push_back(s);
      return;
    }

    for (int i = startIndex; i < s.length(); ++i) {
      if (i > startIndex && s[i] == s[i - 1]) continue;
      if (r > 0 && s[i] == ')')  // delete s[i], then do the dfs
        dfs(s.substr(0, i) + s.substr(i + 1), i, l, r - 1, ans);
      else if (l > 0 && s[i] == '(')  // delete s[i], then do the dfs
        dfs(s.substr(0, i) + s.substr(i + 1), i, l - 1, r, ans);
    }
  }
};