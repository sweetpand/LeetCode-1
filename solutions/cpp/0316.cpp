class Solution {
 public:
  string removeDuplicateLetters(string s) {
    string ans;
    vector<int> count(26);
    vector<bool> used(26);

    for (const char c : s)
      ++count[c - 'a'];

    for (const char c : s) {
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