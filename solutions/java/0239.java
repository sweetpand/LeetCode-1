class Solution {
  public int[] maxSlidingWindow(int[] nums, int k) {
    List<Integer> ans = new ArrayList<>();
    Deque<Integer> decreasingDeque = new ArrayDeque<>();

    for (int i = 0; i < nums.length; ++i) {
      while (!decreasingDeque.isEmpty() && nums[i] > decreasingDeque.getLast())
        decreasingDeque.removeLast();
      decreasingDeque.addLast(nums[i]);
      if (i >= k - 1) {
        ans.add(decreasingDeque.getFirst());
        if (nums[i - k + 1] == decreasingDeque.getFirst())
          decreasingDeque.removeFirst();
      }
    }

    return ans.stream().mapToInt(i -> i).toArray();
  }
}