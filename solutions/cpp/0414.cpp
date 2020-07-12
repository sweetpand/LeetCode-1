class Solution {
 public:
  int thirdMax(vector<int>& nums) {
    long maxi = LONG_MIN;
    long secondMax = LONG_MIN;
    long thirdMax = LONG_MIN;

    for (const int num : nums)
      if (num > maxi) {
        thirdMax = secondMax;
        secondMax = maxi;
        maxi = num;
      } else if (maxi > num && num > secondMax) {
        thirdMax = secondMax;
        secondMax = num;
      } else if (secondMax > num && num > thirdMax) {
        thirdMax = num;
      }

    return thirdMax == LONG_MIN ? maxi : thirdMax;
  }
};