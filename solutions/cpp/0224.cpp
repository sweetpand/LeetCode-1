class Solution {
 public:
  int calculate(string s) {
    int ans = 0;
    int num = 0;
    int sign = 1;
    stack<int> stack{{sign}};

    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      if (isdigit(c))
        num = num * 10 + (c - '0');
      else if (c == '+' || c == '-') {
        ans += sign * num;
        sign = stack.top() * (c == '+' ? 1 : -1);
        num = 0;
      } else if (c == '(')
        stack.push(sign);
      else if (c == ')')
        stack.pop();
    }

    return ans + sign * num;
  }
};