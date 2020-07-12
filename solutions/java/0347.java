class Solution {
  public List<Integer> topKFrequent(int[] nums, int k) {
    List<Integer> ans = new ArrayList<>();
    List<Integer>[] bucket = new List[nums.length + 1];
    Map<Integer, Integer> count = new HashMap<>();

    for (int num : nums)
      count.put(num, count.getOrDefault(num, 0) + 1);

    for (int num : count.keySet()) {
      int freq = count.get(num);
      if (bucket[freq] == null)
        bucket[freq] = new ArrayList<>();
      bucket[freq].add(num);
    }

    for (int freq = bucket.length - 1; freq >= 0; --freq) {
      if (bucket[freq] != null)
        ans.addAll(bucket[freq]);
      if (ans.size() == k)
        return ans;
    }

    throw new IllegalArgumentException();
  }
}