class Solution {
 public:
  int romanToInt(string s) {
    int ans = 0;
    vector<int> roman(24);

    roman['I' - 'A'] = 1;
    roman['V' - 'A'] = 5;
    roman['X' - 'A'] = 10;
    roman['L' - 'A'] = 50;
    roman['C' - 'A'] = 100;
    roman['D' - 'A'] = 500;
    roman['M' - 'A'] = 1000;

    for (int i = 0; i + 1 < s.length(); ++i)
      if (roman[s[i] - 'A'] < roman[s[i + 1] - 'A'])
        ans -= roman[s[i] - 'A'];
      else
        ans += roman[s[i] - 'A'];

    return ans + roman[s.back() - 'A'];
  }
};