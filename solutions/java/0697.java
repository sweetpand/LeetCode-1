class Solution {
  public int findShortestSubArray(int[] nums) {
    int ans = 0;
    int degree = 0;
    Map<Integer, Integer> firstSeen = new HashMap<>();
    Map<Integer, Integer> numCounts = new HashMap<>();

    for (int i = 0; i < nums.length; ++i) {
      firstSeen.putIfAbsent(nums[i], i);
      numCounts.put(nums[i], numCounts.getOrDefault(nums[i], 0) + 1);
      if (numCounts.get(nums[i]) > degree) {
        degree = numCounts.get(nums[i]);
        ans = i - firstSeen.get(nums[i]) + 1;
      } else if (numCounts.get(nums[i]) == degree)
        ans = Math.min(ans, i - firstSeen.get(nums[i]) + 1);
    }

    return ans;
  }
}