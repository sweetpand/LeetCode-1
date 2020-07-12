class Solution {
 public:
  string numberToWords(int num) {
    return num == 0 ? "Zero" : helper(num);
  }

 private:
  const vector<string> belowTwenty{
      "",        "One",     "Two",       "Three",    "Four",
      "Five",    "Six",     "Seven",     "Eight",    "Nine",
      "Ten",     "Eleven",  "Twelve",    "Thirteen", "Fourteen",
      "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
  const vector<string> tens{"",      "Ten",   "Twenty",  "Thirty", "Forty",
                            "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

  string helper(int num) {
    string s;

    if (num < 20)
      s = belowTwenty.at(num);
    else if (num < 100)
      s = tens.at(num / 10) + " " + helper(num % 10);
    else if (num < 1000)
      s = helper(num / 100) + " Hundred " + helper(num % 100);
    else if (num < 1000000)
      s = helper(num / 1000) + " Thousand " + helper(num % 1000);
    else if (num < 1000000000)
      s = helper(num / 1000000) + " Million " + helper(num % 1000000);
    else
      s = helper(num / 1000000000) + " Billion " + helper(num % 1000000000);

    return trim(s);
  }

  string trim(string& s) {
    if (s.empty()) return s;

    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);

    return s;
  }
};