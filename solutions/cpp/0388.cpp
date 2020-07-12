class Solution {
 public:
  int lengthLongestPath(string input) {
    size_t ans = 0;
    stack<pair<int, size_t>> stack{{{-1, 0}}};  // {depth, currentLength}
    stringstream ss(input);

    for (string token; getline(ss, token, '\n');) {
      int depth =
          count_if(begin(token), end(token), [](char c) { return c == '\t'; });
      token.erase(remove(begin(token), end(token), '\t'), end(token));
      while (depth <= stack.top().first)
        stack.pop();
      if (token.find('.') != string::npos)  // file
        ans = max(ans, stack.top().second + token.length());
      else  // directory + '/'
        stack.push({depth, stack.top().second + token.length() + 1});
    }

    return ans;
  }
};