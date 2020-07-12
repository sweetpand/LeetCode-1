class Solution {
  public int nthUglyNumber(int n) {
    List<Integer> nums = new ArrayList<>();
    nums.add(1);
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;

    while (nums.size() < n) {
      int next2 = nums.get(i2) * 2;
      int next3 = nums.get(i3) * 3;
      int next5 = nums.get(i5) * 5;
      int next = Math.min(next2, Math.min(next3, next5));
      if (next == next2)
        ++i2;
      if (next == next3)
        ++i3;
      if (next == next5)
        ++i5;
      nums.add(next);
    }

    return nums.get(nums.size() - 1);
  }
}