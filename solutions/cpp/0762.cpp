class Solution {
 public:
  int countPrimeSetBits(int L, int R) {
    // { 2, 3, 5, 7, 11, 13, 17, 19 }th bits are 1s
    // (10100010100010101100)2 = (665772)10
    constexpr int magic = 665772;
    int ans = 0;

    for (int n = L; n <= R; ++n)
      if (magic & (1 << __builtin_popcountll(n)))
        ++ans;

    return ans;
  }
};