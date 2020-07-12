class Solution {
  public List<String> summaryRanges(int[] nums) {
    List<String> ans = new ArrayList<>();

    for (int i = 0; i < nums.length; ++i) {
      int begin = nums[i];
      while (i < nums.length - 1 && nums[i] == nums[i + 1] - 1)
        ++i;
      int end = nums[i];
      if (begin == end)
        ans.add("" + begin);
      else
        ans.add("" + begin + "->" + end);
    }

    return ans;
  }
}