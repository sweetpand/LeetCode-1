class Solution {
  public int nthSuperUglyNumber(int n, int[] primes) {
    final int k = primes.length;

    List<Integer> nums = new ArrayList<>();
    nums.add(1);
    int[] indices = new int[k];

    while (nums.size() < n) {
      int[] nexts = new int[k];
      for (int i = 0; i < k; ++i)
        nexts[i] = nums.get(indices[i]) * primes[i];
      int next = Arrays.stream(nexts).min().getAsInt();
      for (int i = 0; i < k; ++i)
        if (next == nexts[i])
          ++indices[i];
      nums.add(next);
    }

    return nums.get(nums.size() - 1);
  }
}