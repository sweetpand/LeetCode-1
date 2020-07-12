class Solution {
  public int evalRPN(String[] tokens) {
    Stack<Integer> stack = new Stack<Integer>();

    for (final String token : tokens)
      switch (token) {
      case "+":
        stack.push(stack.pop() + stack.pop());
        break;
      case "-":
        stack.push(-stack.pop() + stack.pop());
        break;
      case "*":
        stack.push(stack.pop() * stack.pop());
        break;
      case "/":
        int b = stack.pop();
        int a = stack.pop();
        stack.push(a / b);
        break;
      default:
        stack.push(Integer.valueOf(token));
      }

    return stack.peek();
  }
}