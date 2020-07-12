class Solution {
  public int romanToInt(String s) {
    int ans = 0;
    int[] roman = new int[24];

    roman['I' - 'A'] = 1;
    roman['V' - 'A'] = 5;
    roman['X' - 'A'] = 10;
    roman['L' - 'A'] = 50;
    roman['C' - 'A'] = 100;
    roman['D' - 'A'] = 500;
    roman['M' - 'A'] = 1000;

    for (int i = 0; i + 1 < s.length(); ++i) {
      if (roman[s.charAt(i) - 'A'] < roman[s.charAt(i + 1) - 'A'])
        ans -= roman[s.charAt(i) - 'A'];
      else
        ans += roman[s.charAt(i) - 'A'];
    }

    return ans + roman[s.charAt(s.length() - 1) - 'A'];
  }
}