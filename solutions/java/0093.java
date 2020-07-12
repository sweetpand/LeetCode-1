class Solution {
  public List<String> restoreIpAddresses(String s) {
    List<String> ans = new ArrayList<>();

    dfs(s, 0, new ArrayList<>(), ans);

    return ans;
  }

  private void dfs(final String s, int index, List<String> path, List<String> ans) {
    if (path.size() == 4 && index == s.length()) {
      ans.add(path.get(0) + '.' + path.get(1) + '.' + path.get(2) + '.' + path.get(3));
      return;
    }
    if (path.size() == 4 || index == s.length())
      return;

    for (int i = 1; i <= 3; ++i) {
      if (index + i > s.length())
        return;
      if (i > 1 && s.charAt(index) == '0')
        return;
      String num = s.substring(index, index + i);
      if (Integer.valueOf(num) > 255)
        return;
      path.add(num);
      dfs(s, index + i, path, ans);
      path.remove(path.size() - 1);
    }
  }
}