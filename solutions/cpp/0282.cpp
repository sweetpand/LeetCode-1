class Solution {
 public:
  vector<string> addOperators(string num, int target) {
    vector<string> ans;
    vector<string> path;

    auto join = [](vector<string>& path) {
      string joined;
      for (const string& s : path) joined += s;
      return joined;
    };

    function<void(int, long, long)> dfs = [&](int s, long eval,
                                              long multiplied) {
      if (s == num.length() && eval == target) {
        ans.push_back(join(path));
        return;
      }

      for (int i = 1; i <= num.length() - s; ++i) {
        const string t = num.substr(s, i);  // current substring
        if (i > 1 && t[0] == '0') continue;
        const long curr = stol(t);  // current substring's number
        if (s == 0) {
          path.push_back(t);
          dfs(i, curr, curr);
          path.pop_back();
          continue;
        }

        for (const string& op : {"+", "-", "*"}) {
          path.push_back(op);
          path.push_back(t);
          if (op == "+")
            dfs(s + i, eval + curr, curr);
          else if (op == "-")
            dfs(s + i, eval - curr, -curr);
          else
            dfs(s + i, eval - multiplied + multiplied * curr,
                multiplied * curr);
          path.pop_back();
          path.pop_back();
        }
      }
    };

    dfs(0, 0, 0);

    return ans;
  }
};