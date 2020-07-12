class Solution {
 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int>> ans;
    unordered_map<string, int> map;

    for (int i = 0; i < words.size(); ++i) {
      string word = words[i];
      reverse(begin(word), end(word));
      map[word] = i;
    }

    for (int i = 0; i < words.size(); ++i) {
      if (map.count("") && map[""] != i && isPalindrome(words[i]))
        ans.push_back({i, map[""]});

      for (int j = 1; j <= words[i].length(); ++j) {
        const string l = words[i].substr(0, j);
        const string r = words[i].substr(j, words[i].length() - j);
        if (map.count(l) && map[l] != i && isPalindrome(r))
          ans.push_back({i, map[l]});
        if (map.count(r) && map[r] != i && isPalindrome(l))
          ans.push_back({map[r], i});
      }
    }

    return ans;
  }

 private:
  bool isPalindrome(const string& s) {
    int l = 0;
    int r = s.length() - 1;
    while (l < r)
      if (s[l++] != s[r--])
        return false;
    return true;
  }
};