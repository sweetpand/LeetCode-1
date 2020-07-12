public class Solution {
  public int thirdMax(int[] nums) {
    Queue<Integer> pq = new PriorityQueue<>();
    Set<Integer> seen = new HashSet<>();

    for (int num : nums)
      if (seen.add(num)) {
        pq.add(num);
        if (pq.size() > 3)
          pq.poll();
      }

    if (pq.size() == 2)
      pq.poll();

    return pq.peek();
  }
}