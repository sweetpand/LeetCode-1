class Solution {
  public int findMinArrowShots(int[][] points) {
    int ans = 0;
    long arrowX = (long) Integer.MIN_VALUE - 1;

    Arrays.sort(points, (a, b) -> a[1] - b[1]);

    for (int[] point : points)
      if (point[0] > arrowX) {
        ++ans;
        arrowX = point[1];
      }

    return ans;
  }
}