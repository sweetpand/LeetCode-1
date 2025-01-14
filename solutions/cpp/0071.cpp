class Solution {
 public:
  string simplifyPath(string path) {
    string ans;
    string temp;
    stringstream ss(path);
    vector<string> stack;

    while (getline(ss, temp, '/')) {
      if (temp == "" || temp == ".") continue;
      if (temp == "..") {
        if (!stack.empty()) stack.pop_back();
      } else {
        stack.push_back(temp);
      }
    }

    for (const string& s : stack)
      ans += "/" + s;

    return ans.empty() ? "/" : ans;
  }
};