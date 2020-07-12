class Solution {
  public int maxRotateFunction(int[] A) {
    int sum = Arrays.stream(A).sum();
    int f = 0;

    for (int i = 0; i < A.length; ++i)
      f += i * A[i];

    int ans = f;

    for (int i = A.length - 1; i >= 0; --i) {
      f += sum - A.length * A[i];
      ans = Math.max(ans, f);
    }

    return ans;
  }
}