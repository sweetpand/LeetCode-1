class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    vector<string> ans{""};
    const unordered_map<char, string> digitToLetters{
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    for (const char d : digits) {
      vector<string> temp;
      for (const string& s : ans)
        for (const char c : digitToLetters.at(d))
          temp.push_back(s + c);
      swap(ans, temp);
    }

    return ans;
  }
};