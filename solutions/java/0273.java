class Solution {
  public String numberToWords(int num) {
    return num == 0 ? "Zero" : helper(num);
  }

  private String[] belowTwenty = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
      "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
  private String[] tens = { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

  private String helper(int num) {
    String s = "";

    if (num < 20)
      s = belowTwenty[num];
    else if (num < 100)
      s = tens[num / 10] + " " + helper(num % 10);
    else if (num < 1000)
      s = helper(num / 100) + " Hundred " + helper(num % 100);
    else if (num < 1000000)
      s = helper(num / 1000) + " Thousand " + helper(num % 1000);
    else if (num < 1000000000)
      s = helper(num / 1000000) + " Million " + helper(num % 1000000);
    else
      s = helper(num / 1000000000) + " Billion " + helper(num % 1000000000);

    return s.trim();
  }
}