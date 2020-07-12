class Solution {
 public:
  int maximumProduct(vector<int>& nums) {
    int min = INT_MAX;
    int secondMin = INT_MAX;
    int max = INT_MIN;
    int secondMax = INT_MIN;
    int thirdMax = INT_MIN;

    for (const int num : nums) {
      if (num <= min) {
        secondMin = min;
        min = num;
      } else if (num <= secondMin) {
        secondMin = num;
      }

      if (num >= max) {
        thirdMax = secondMax;
        secondMax = max;
        max = num;
      } else if (num >= secondMax) {
        thirdMax = secondMax;
        secondMax = num;
      } else if (num >= thirdMax) {
        thirdMax = num;
      }
    }

    return std::max(min * secondMin * max, max * secondMax * thirdMax);
  }
};