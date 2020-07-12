class Solution {
 public:
  string reorganizeString(string S) {
    const int n = S.length();

    vector<int> count(26);

    for (const char c : S)
      ++count[c - 'a'];

    const int maxCount = *max_element(begin(count), end(count));
    if (maxCount > (n + 1) / 2) return "";

    string ans(n, ' ');
    const bool shouldFillEvenIndices = maxCount == (n + 1) / 2;

    // fill in 0, 2, 4, ... positions with the maxCount char
    if (shouldFillEvenIndices) {
      const int c = getMaxCountChar(count, maxCount);
      for (int i = 0; i < n; i += 2)
        ans[i] = c;
      count[c - 'a'] = 0;
    }

    // start index of remaining chars should be 0 or 1
    int i = shouldFillEvenIndices;
    for (char c = 'a'; c <= 'z'; ++c)
      while (count[c - 'a']-- > 0) {
        ans[i] = c;
        i += 2;
        if (i >= n)  // out-of-bound, reset the index to 1
          i = 1;
      }

    return ans;
  }

 private:
  char getMaxCountChar(vector<int>& count, int maxCount) {
    for (int i = 0; i < 26; ++i)
      if (count[i] == maxCount)
        return 'a' + i;
    throw;
  }
};