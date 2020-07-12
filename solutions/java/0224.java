class Solution {
  public int calculate(String s) {
    int ans = 0;
    int num = 0;
    int sign = 1;
    Stack<Integer> stack = new Stack<>();
    stack.push(sign);

    for (int i = 0; i < s.length(); ++i) {
      char c = s.charAt(i);
      if (Character.isDigit(c))
        num = num * 10 + (c - '0');
      else if (c == '+' || c == '-') {
        ans += sign * num;
        sign = stack.peek() * (c == '+' ? 1 : -1);
        num = 0;
      } else if (c == '(')
        stack.push(sign);
      else if (c == ')')
        stack.pop();
    }

    return ans + sign * num;
  }
}