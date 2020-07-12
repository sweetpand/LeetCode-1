class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<int> ans;
    vector<int> letterToRightmostIndex(26);

    for (int i = 0; i < S.length(); ++i)
      letterToRightmostIndex[S[i] - 'a'] = i;

    int l = 0;
    int r = 0;

    for (int i = 0; i < S.length(); ++i) {
      r = max(r, letterToRightmostIndex[S[i] - 'a']);
      if (i == r) {
        ans.push_back(r - l + 1);
        l = r + 1;
      }
    }

    return ans;
  }
};