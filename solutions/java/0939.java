class Solution {
  public int minAreaRect(int[][] points) {
    int ans = Integer.MAX_VALUE;
    Map<Integer, Set<Integer>> xToYs = new HashMap<>();

    for (int[] point : points) {
      if (!xToYs.containsKey(point[0]))
        xToYs.put(point[0], new HashSet<>());
      xToYs.get(point[0]).add(point[1]);
    }

    for (int i = 0; i < points.length; ++i)
      for (int j = 0; j < i; ++j) {
        if (points[i][0] == points[j][0] || points[i][1] == points[j][1])
          continue;
        if (xToYs.get(points[i][0]).contains(points[j][1]) && xToYs.get(points[j][0]).contains(points[i][1]))
          ans = Math.min(ans, Math.abs(points[i][0] - points[j][0]) * Math.abs(points[i][1] - points[j][1]));
      }

    return ans < Integer.MAX_VALUE ? ans : 0;
  }
}