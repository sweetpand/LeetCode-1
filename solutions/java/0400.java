class Solution {
  public int findNthDigit(int n) {
    int digitSize = 1;
    int startNum = 1;

    for (long count = 9; digitSize * count < n; count *= 10) {
      n -= digitSize * count;
      ++digitSize;
      startNum *= 10;
    }

    int targetNum = startNum + (n - 1) / digitSize;
    int pos = n % digitSize;

    return getDigit(targetNum, pos, digitSize);
  }

  private int getDigit(int num, int pos, int digitSize) {
    if (pos == 0)
      return num % 10;

    for (int i = 0; i < digitSize - pos; ++i)
      num /= 10;

    return num % 10;
  }
}