class Solution {
  public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
    int ans = 0;
    Map<Integer, Integer> count = new HashMap<>();

    for (int a : A)
      for (int b : B)
        count.put(a + b, count.getOrDefault(a + b, 0) + 1);

    for (int c : C)
      for (int d : D)
        if (count.containsKey(-c - d))
          ans += count.get(-c - d);

    return ans;
  }
}