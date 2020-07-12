class Solution {
 public:
  vector<int> movesToStamp(string stamp, string target) {
    vector<int> ans;
    vector<bool> stamped(target.length());
    int stampedCount = 0;

    while (stampedCount < target.length()) {
      bool isStamped = false;
      for (int i = 0; i <= target.length() - stamp.length(); ++i) {
        if (stamped[i]) continue;
        int stampified = stampify(stamp, target, i);
        if (stampified == 0) continue;
        stampedCount += stampified;
        isStamped = true;
        stamped[i] = true;
        ans.push_back(i);
      }
      if (!isStamped) return {};
    }

    reverse(begin(ans), end(ans));

    return ans;
  }

 private:
  int stampify(const string& stamp, string& target, int s) {
    int stampified = stamp.length();

    for (int i = 0; i < stamp.length(); ++i)
      if (target[s + i] == '*')
        --stampified;
      else if (target[s + i] != stamp[i])
        return 0;

    fill(begin(target) + s, begin(target) + s + stamp.length(), '*');

    return stampified;
  }
};