class MinStack {
 public:
  void push(int x) {
    int mini = stack.empty() ? x : min(stack.top().second, x);
    stack.push({x, mini});
  }

  void pop() {
    stack.pop();
  }

  int top() {
    return stack.top().first;
  }

  int getMin() {
    return stack.top().second;
  }

 private:
  stack<pair<int, int>> stack;
};