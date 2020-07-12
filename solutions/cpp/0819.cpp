class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string>& banned) {
    pair<string, int> ans{"", 0};
    unordered_set<string> bannedSet{begin(banned), end(banned)};
    unordered_map<string, int> count;

    for (char& c : paragraph) c = isalpha(c) ? tolower(c) : ' ';

    istringstream iss(paragraph);
    string word;

    while (iss >> word)
      if (!bannedSet.count(word) && ++count[word] > ans.second)
        ans = {word, count[word]};

    return ans.first;
  }
};