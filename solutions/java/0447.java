class Solution {
  public int numberOfBoomerangs(int[][] points) {
    int ans = 0;

    for (int[] p1 : points) {
      Map<Integer, Integer> count = new HashMap<>();
      for (int[] p2 : points) {
        int distance = (int) Math.pow(p1[0] - p2[0], 2) + (int) Math.pow(p1[1] - p2[1], 2);
        ans += 2 * count.getOrDefault(distance, 0);
        count.put(distance, count.getOrDefault(distance, 0) + 1);
      }
    }

    return ans;
  }
}