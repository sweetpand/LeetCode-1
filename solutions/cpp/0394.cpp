class Solution {
 public:
  string decodeString(string s) {
    stack<string> stack;
    string currStr;
    int currNum = 0;

    for (const char c : s)
      if (isdigit(c)) {
        currNum = currNum * 10 + c - '0';
      } else if (c == '[') {
        stack.push(currStr);
        stack.push(to_string(currNum));
        currStr = "";
        currNum = 0;
      } else if (c == ']') {
        int repeatedTime = stoi(stack.top()); stack.pop();
        string repeatedStr;
        while (repeatedTime--)
          repeatedStr += currStr;
        string prevStr = stack.top(); stack.pop();
        currStr = prevStr + repeatedStr;
      } else {
        currStr += c;
      }

    return currStr;
  }
};