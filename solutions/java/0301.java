class Solution {
  public List<String> removeInvalidParentheses(String s) {
    List<String> ans = new ArrayList<>();
    int l = 0;
    int r = 0;

    for (final char c : s.toCharArray())
      if (c == '(')
        ++l;
      else if (c == ')') {
        if (l == 0)
          ++r;
        else
          --l;
      }

    dfs(s, 0, l, r, ans);

    return ans;
  }

  private boolean isValid(final String s) {
    int count = 0;
    for (final char c : s.toCharArray()) {
      if (c == '(')
        ++count;
      else if (c == ')')
        --count;
      if (count < 0)
        return false;
    }
    return true;
  }

  private void dfs(final String s, int start, int l, int r, List<String> ans) {
    if (l == 0 && r == 0 && isValid(s)) {
      ans.add(s);
      return;
    }

    for (int i = start; i < s.length(); ++i) {
      if (i > start && s.charAt(i) == s.charAt(i - 1))
        continue;
      if (r > 0 && s.charAt(i) == ')')
        dfs(s.substring(0, i) + s.substring(i + 1), i, l, r - 1, ans);
      else if (l > 0 && s.charAt(i) == '(')
        dfs(s.substring(0, i) + s.substring(i + 1), i, l - 1, r, ans);
    }
  }
}