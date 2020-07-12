class Solution {
 public:
  string customSortString(string S, string T) {
    string ans;
    vector<int> count(26);

    for (const char c : T)
      ++count[c - 'a'];

    for (const char c : S)
      while (count[c - 'a']-- > 0)
        ans += c;

    for (char c = 'a'; c <= 'z'; ++c)
      while (count[c - 'a']-- > 0)
        ans += c;

    return ans;
  }
};