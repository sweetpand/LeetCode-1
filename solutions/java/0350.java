class Solution {
  public int[] intersect(int[] nums1, int[] nums2) {
    List<Integer> ans = new ArrayList<>();
    Map<Integer, Integer> count = new HashMap<>();

    for (int num : nums1)
      count.put(num, count.getOrDefault(num, 0) + 1);

    for (int num : nums2)
      if (count.getOrDefault(num, 0) > 0) {
        ans.add(num);
        count.put(num, count.get(num) - 1);
      }

    return ans.stream().mapToInt(i -> i).toArray();
  }
}