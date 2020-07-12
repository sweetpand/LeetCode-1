class Solution {
 public:
  string addBinary(string a, string b) {
    string ans;
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;

    while (carry == 1 || i >= 0 || j >= 0) {
      if (i >= 0) carry += a[i--] - '0';
      if (j >= 0) carry += b[j--] - '0';
      ans += char(carry % 2 + '0');
      carry >>= 1;
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};