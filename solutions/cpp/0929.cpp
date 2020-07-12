class Solution {
 public:
  int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> seen;

    for (const string& email : emails) {
      string local;
      for (char c : email) {
        if (c == '+' || c == '@') break;
        if (c == '.') continue;
        local += c;
      }
      string atDomain = email.substr(email.find('@'));
      seen.insert(local + atDomain);
    }

    return seen.size();
  }
};