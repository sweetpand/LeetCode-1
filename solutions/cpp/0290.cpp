class Solution {
 public:
  bool wordPattern(string pattern, string str) {
    const int n = pattern.length();

    vector<int> charToIndex(26);
    unordered_map<string, int> stringToIndex;
    istringstream iss(str);

    int i = 0;
    for (string word; iss >> word; ++i) {
      if (i == n || charToIndex[pattern[i] - 'a'] != stringToIndex[word])
        return false;
      charToIndex[pattern[i] - 'a'] = i + 1;
      stringToIndex[word] = i + 1;
    }

    return i == n;
  }
};