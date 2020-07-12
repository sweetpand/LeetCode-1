class Solution {
 public:
  int findNthDigit(int n) {
    int digitSize = 1;
    int startNum = 1;
    long count = 9;

    while (digitSize * count < n) {
      n -= digitSize * count;
      ++digitSize;
      startNum *= 10;
      count *= 10;
    }

    int targetNum = startNum + (n - 1) / digitSize;
    const int pos = n % digitSize;

    if (pos == 0) return targetNum % 10;

    for (int i = 0; i < digitSize - pos; ++i)
      targetNum /= 10;

    return targetNum % 10;
  }
};