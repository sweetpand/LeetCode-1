class Solution {
  public int maxProfit(int[] prices) {
    int sell = 0;
    int hold = Integer.MIN_VALUE;
    int prev = 0;

    for (int price : prices) {
      int cache = sell;
      sell = Math.max(sell, hold + price);
      hold = Math.max(hold, prev - price);
      prev = cache;
    }

    return sell;
  }
}