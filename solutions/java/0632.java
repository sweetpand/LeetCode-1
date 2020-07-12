class Solution {
  public int[] smallestRange(List<List<Integer>> nums) {
    Queue<Elem> pq = new PriorityQueue<>((e1, e2) -> e1.value - e2.value);

    int maxRange = Integer.MIN_VALUE;
    for (int i = 0; i < nums.size(); ++i) {
      pq.add(new Elem(nums.get(i).get(0), i, 0));
      maxRange = Math.max(maxRange, nums.get(i).get(0));
    }
    int minRange = pq.peek().value;

    int[] ans = new int[] { minRange, maxRange };

    while (pq.size() == nums.size()) {
      Elem elem = pq.poll();
      if (elem.c + 1 < nums.get(elem.r).size()) {
        pq.add(new Elem(nums.get(elem.r).get(elem.c + 1), elem.r, elem.c + 1));
        maxRange = Math.max(maxRange, nums.get(elem.r).get(elem.c + 1));
        minRange = pq.peek().value;
        if (maxRange - minRange < ans[1] - ans[0]) {
          ans[0] = minRange;
          ans[1] = maxRange;
        }
      }
    }

    return ans;
  }

  private class Elem {
    int value;
    int r;
    int c;

    public Elem(int value, int r, int c) {
      this.value = value;
      this.r = r;
      this.c = c;
    }
  }
}