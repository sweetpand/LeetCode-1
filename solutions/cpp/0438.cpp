class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> ans;
    vector<int> count(26);
    int required = p.length();

    for (const char c : p)
      ++count[c - 'a'];

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (--count[s[r] - 'a'] >= 0)
        --required;
      while (required == 0) {
        if (r - l + 1 == p.length())
          ans.push_back(l);
        if (++count[s[l++] - 'a'] > 0)
          ++required;
      }
    }

    return ans;
  }
};