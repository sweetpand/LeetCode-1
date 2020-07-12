class Solution {
 public:
  string smallestSubsequence(string text) {
    string ans;
    vector<int> count(26);
    vector<bool> used(26);

    for (char c : text) ++count[c - 'a'];

    for (char c : text) {
      --count[c - 'a'];
      if (used[c - 'a']) continue;
      while (!ans.empty() && ans.back() > c && count[ans.back() - 'a'] > 0) {
        used[ans.back() - 'a'] = false;
        ans.pop_back();
      }
      ans += c;
      used[c - 'a'] = true;
    }

    return ans;
  }
};