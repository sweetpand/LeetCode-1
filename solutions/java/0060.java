class Solution {
  public String getPermutation(int n, int k) {
    StringBuilder ans = new StringBuilder();
    List<Integer> nums = new ArrayList<>();
    int[] factorial = new int[n];

    for (int i = 1; i <= n; ++i)
      nums.add(i);

    Arrays.fill(factorial, 1);
    for (int i = 1; i < n; ++i)
      factorial[i] = factorial[i - 1] * i;

    --k;

    for (int i = n; i > 0; --i) {
      int j = k / factorial[i - 1];
      k %= factorial[i - 1];
      ans.append(nums.get(j));
      nums.remove(j);
    }

    return ans.toString();
  }
}