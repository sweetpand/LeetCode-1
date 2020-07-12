class Solution {
  public int[] intersection(int[] nums1, int[] nums2) {
    List<Integer> ans = new ArrayList<>();
    Set<Integer> set = new HashSet<>();

    for (int num : nums1)
      set.add(num);

    for (int num : nums2)
      if (set.remove(num))
        ans.add(num);

    return ans.stream().mapToInt(i -> i).toArray();
  }
}