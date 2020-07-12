class Solution {
  public int[][] insert(int[][] intervals, int[] newInterval) {
    List<int[]> ans = new ArrayList<>();
    List<int[]> intervalsList = new ArrayList<>(Arrays.asList(intervals));

    int i = 0;
    for (; i < intervals.length; ++i)
      if (intervals[i][0] >= newInterval[0])
        break;
    intervalsList.add(i, newInterval);

    for (int[] interval : intervalsList) {
      if (ans.isEmpty() || ans.get(ans.size() - 1)[1] < interval[0])
        ans.add(interval);
      else
        ans.get(ans.size() - 1)[1] = Math.max(ans.get(ans.size() - 1)[1], interval[1]);
    }

    return ans.toArray(new int[ans.size()][]);
  }
}