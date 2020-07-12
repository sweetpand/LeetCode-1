class Solution {
  public List<Integer> largestDivisibleSubset(int[] nums) {
    final int n = nums.length;

    List<Integer> ans = new ArrayList<>();
    int[] count = new int[n];
    int[] prevIndex = new int[n];
    int maxCount = 0;
    int index = -1;

    Arrays.fill(count, 1);
    Arrays.fill(prevIndex, -1);
    Arrays.sort(nums);

    for (int i = 0; i < n; ++i) {
      for (int j = i - 1; j >= 0; --j)
        if (nums[i] % nums[j] == 0 && count[i] < count[j] + 1) {
          count[i] = count[j] + 1;
          prevIndex[i] = j;
        }
      if (count[i] > maxCount) {
        maxCount = count[i];
        index = i;
      }
    }

    while (index != -1) {
      ans.add(nums[index]);
      index = prevIndex[index];
    }

    return ans;
  }
}