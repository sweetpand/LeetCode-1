class Solution {
  public int findNumberOfLIS(int[] nums) {
    int ans = 0;
    int maxLength = 0;
    int[] length = new int[nums.length];
    int[] count = new int[nums.length];

    Arrays.fill(length, 1);
    Arrays.fill(count, 1);

    for (int i = 0; i < nums.length; ++i) {
      for (int j = 0; j < i; ++j)
        if (nums[j] < nums[i]) {
          if (length[i] == length[j] + 1)
            count[i] += count[j];
          else if (length[i] < length[j] + 1) {
            length[i] = length[j] + 1;
            count[i] = count[j];
          }
        }
      if (maxLength == length[i])
        ans += count[i];
      else if (maxLength < length[i]) {
        maxLength = length[i];
        ans = count[i];
      }
    }

    return ans;
  }
}