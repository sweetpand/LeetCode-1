class Solution {
 public:
  uint32_t reverseBits(uint32_t num) {
    uint32_t ans = 0;

    for (int i = 0; i < 32; ++i)
      if ((num >> i) & 1)
        ans |= (1 << (31 - i));

    return ans;
  }
};