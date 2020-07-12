class Solution {
  public int maximumProduct(int[] nums) {
    int min = Integer.MAX_VALUE;
    int secondMin = Integer.MAX_VALUE;
    int max = Integer.MIN_VALUE;
    int secondMax = Integer.MIN_VALUE;
    int thirdMax = Integer.MIN_VALUE;

    for (int num : nums) {
      if (num <= min) {
        secondMin = min;
        min = num;
      } else if (num <= secondMin)
        secondMin = num;

      if (num >= max) {
        thirdMax = secondMax;
        secondMax = max;
        max = num;
      } else if (num >= secondMax) {
        thirdMax = secondMax;
        secondMax = num;
      } else if (num >= thirdMax)
        thirdMax = num;
    }

    return Math.max(min * secondMin * max, max * secondMax * thirdMax);
  }
}