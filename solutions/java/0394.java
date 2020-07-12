class Solution {
  public String decodeString(String s) {
    String currStr = "";
    int currNum = 0;
    Stack<String> stack = new Stack<>();

    for (char c : s.toCharArray()) {
      if (Character.isDigit(c))
        currNum = currNum * 10 + c - '0';
      else if (c == '[') {
        stack.push(currStr);
        stack.push(String.valueOf(currNum));
        currStr = "";
        currNum = 0;
      } else if (c == ']') {
        int num = Integer.valueOf(stack.pop());
        String prevStr = stack.pop();
        String repeated = "";
        for (int i = 0; i < num; ++i)
          repeated += currStr;
        currStr = prevStr + repeated;
      } else
        currStr += c;
    }

    return currStr;
  }
}