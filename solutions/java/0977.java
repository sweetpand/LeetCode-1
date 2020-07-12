class Solution {
  public int[] sortedSquares(int[] A) {
    int n = A.length;
    int l = 0;
    int r = n - 1;
    int[] ans = new int[n];

    while (l <= r)
      ans[--n] = Math.abs(A[l]) > Math.abs(A[r]) ? A[l] * A[l++] : A[r] * A[r--];

    return ans;
  }
}