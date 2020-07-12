class Solution {
 public:
  int maxProduct(vector<string>& words) {
    size_t ans = 0;
    vector<int> masks;

    for (const string& word : words) {
      int mask = 0;
      for (int i = 0; i < word.length(); ++i)
        mask |= 1 << (word[i] - 'a');
      masks.push_back(mask);
    }

    for (int i = 0; i < words.size(); ++i)
      for (int j = i + 1; j < words.size(); ++j)
        if ((masks[i] & masks[j]) == 0)
          ans = max(ans, words[i].length() * words[j].length());

    return ans;
  }
};