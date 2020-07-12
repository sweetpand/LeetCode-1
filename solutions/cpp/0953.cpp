class Solution {
 public:
  bool isAlienSorted(vector<string>& words, string order) {
    unordered_map<char, char> map;

    for (int i = 0; i < 26; ++i) map[order[i]] = (char)(i + 'a');

    for (string& word : words)
      for (char& c : word) c = map[c];

    return is_sorted(begin(words), end(words));
  }
};