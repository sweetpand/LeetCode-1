class Solution {
  public int maxPoints(int[][] points) {
    int ans = 0;

    for (int i = 0; i < points.length; ++i) {
      Map<Pair<Integer, Integer>, Integer> count = new HashMap<>();
      int[] p1 = points[i];
      int samePoints = 1;
      int maxPoints = 0;
      for (int j = i + 1; j < points.length; ++j) {
        int[] p2 = points[j];
        if (p1[0] == p2[0] && p1[1] == p2[1])
          ++samePoints;
        else {
          Pair<Integer, Integer> slope = getSlope(p1, p2);
          count.put(slope, count.getOrDefault(slope, 0) + 1);
          maxPoints = Math.max(maxPoints, count.get(slope));
        }
      }
      ans = Math.max(ans, samePoints + maxPoints);
    }

    return ans;
  }

  private Pair<Integer, Integer> getSlope(int[] p1, int[] p2) {
    int dx = p2[0] - p1[0];
    int dy = p2[1] - p1[1];

    if (dx == 0)
      return new Pair<>(0, p1[0]);
    if (dy == 0)
      return new Pair<>(p1[1], 0);

    int d = gcd(dx, dy);

    return new Pair<>(dx / d, dy / d);
  }

  private int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }
}