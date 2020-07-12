class Solution {
 public:
  bool isPowerOfFour(int num) {
    return num > 0 && __builtin_popcountll(num) == 1 && (num - 1) % 3 == 0;
  }
};