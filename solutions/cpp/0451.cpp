class Solution {
 public:
  string frequencySort(string s) {
    const int n = s.length();

    string ans;
    vector<vector<char>> bucket(n + 1);
    vector<int> count(128);

    for (const char c : s)
      ++count[c];

    for (int i = 0; i < 128; ++i)
      if (count[i])
        bucket[count[i]].push_back(i);

    for (int freq = n; freq > 0; --freq)
      for (const char c : bucket[freq])
        for (int i = 0; i < freq; ++i)
          ans += c;

    return ans;
  }
};