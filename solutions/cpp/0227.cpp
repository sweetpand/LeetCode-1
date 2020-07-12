class Solution {
 public:
  int calculate(string s) {
    int ans = 0;
    int num = 0;
    char sign = '+';
    stack<int> stack;

    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      if (isdigit(c)) num = num * 10 + (c - '0');
      if (!isdigit(c) && !isspace(c) || i == s.length() - 1) {
        switch (sign) {
          case '+':
            stack.push(num);
            break;
          case '-':
            stack.push(-num);
            break;
          case '*':
            num = stack.top() * num, stack.pop();
            stack.push(num);
            break;
          default:
            num = stack.top() / num, stack.pop();
            stack.push(num);
        }
        num = 0;
        sign = c;
      }
    }

    while (!stack.empty())
      ans += stack.top(), stack.pop();

    return ans;
  }
};