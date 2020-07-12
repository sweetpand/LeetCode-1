class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;

    function<void(const string&, int, int)> helper = [&](const string str,
                                                         int l, int r) {
      if (l == 0 && r == 0) ans.push_back(str);
      if (l > 0) helper(str + '(', l - 1, r);
      if (l < r) helper(str + ')', l, r - 1);
    };

    helper("", n, n);

    return ans;
  }
};