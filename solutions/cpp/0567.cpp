class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    vector<int> count1(26);
    int required = s1.length();

    for (const char c : s1)
      ++count1[c - 'a'];

    for (int r = 0; r < s2.length(); ++r) {
      if (--count1[s2[r] - 'a'] >= 0)
        --required;
      if (r >= s1.length()) // the window is oversized
        if (++count1[s2[r - s1.length()] - 'a'] > 0)
          ++required;
      if (required == 0) return true;
    }

    return false;
  }
};