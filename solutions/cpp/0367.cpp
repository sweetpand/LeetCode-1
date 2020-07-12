class Solution {
 public:
  bool isPerfectSquare(long num) {
    long l = 1;
    long r = num + 1;

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (m > num / m)
        r = m;
      else
        l = m + 1;
    }

    return (l - 1) * (l - 1) == num;
  }
};