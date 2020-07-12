class Solution {
 public:
  int longestSubstring(string s, int k) {
    int ans = 0;

    for (int i = 1; i <= 26; ++i)
      ans = max(ans, longestSubstringWithNUniqueCharacters(s, k, i));

    return ans;
  }

 private:
  int longestSubstringWithNUniqueCharacters(const string& s, int k, int n) {
    int ans = 0;
    int uniqueNums = 0;
    int noLessThanK = 0;
    vector<int> count(26);

    for (int l = 0, r = 0; r < s.length(); ++r) {
      if (count[s[r] - 'a'] == 0) ++uniqueNums;
      if (++count[s[r] - 'a'] == k) ++noLessThanK;
      while (uniqueNums > n) {
        if (count[s[l] - 'a'] == k) --noLessThanK;
        if (--count[s[l++] - 'a'] == 0) --uniqueNums;
      }
      if (noLessThanK == n) ans = max(ans, r - l + 1);
    }

    return ans;
  }
};