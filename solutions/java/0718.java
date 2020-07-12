class Solution {
  public int findLength(int[] A, int[] B) {
    int ans = 0;
    int[] dp = new int[B.length + 1];

    for (int i = A.length - 1; i >= 0; --i)
      for (int j = 0; j < B.length; ++j) {
        dp[j] = A[i] == B[j] ? dp[j + 1] + 1 : 0;
        ans = Math.max(ans, dp[j]);
      }

    return ans;
  }
}