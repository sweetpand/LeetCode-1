class Solution {
  public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
    if (nums1.length == 0 || nums2.length == 0 || k == 0)
      return new ArrayList<>();

    List<List<Integer>> ans = new ArrayList<>();
    PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> (nums1[a[0]] + nums2[a[1]]) - (nums1[b[0]] + nums2[b[1]]));

    for (int i = 0; i < nums1.length && i < k; ++i)
      pq.offer(new int[] { i, 0 });

    while (k-- > 0 && !pq.isEmpty()) {
      int[] index = pq.poll();
      ans.add(Arrays.asList(nums1[index[0]], nums2[index[1]]));
      if (index[1] < nums2.length - 1)
        pq.offer(new int[] { index[0], index[1] + 1 });
    }

    return ans;
  }
}