class Solution {
 public:
  int maximumSwap(int num) {
    string s = to_string(num);
    unordered_map<char, int> digitToIndex;

    for (int i = 0; i < s.length(); ++i)
      digitToIndex[s[i]] = i;

    for (int i = 0; i < s.length(); ++i)
      for (char d = '9'; d > s[i]; --d)
        if (digitToIndex.count(d) && digitToIndex[d] > i) {
          swap(s[i], s[digitToIndex[d]]);
          return stoi(s);
        }

    return num;
  }
};