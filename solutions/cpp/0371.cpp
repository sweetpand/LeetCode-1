class Solution {
 public:
  int getSum(unsigned a, unsigned b) {
    while (b != 0) {
      const unsigned sum = a ^ b;
      b = (a & b) << 1;
      a = sum;
    }

    return a;
  }
};