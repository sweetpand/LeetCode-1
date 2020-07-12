class Solution {
  public int[] movesToStamp(String stamp, String target) {
    List<Integer> ans = new ArrayList<>();
    char[] targetCharArray = target.toCharArray();
    boolean[] stamped = new boolean[target.length()];
    int stampedCount = 0;

    while (stampedCount < targetCharArray.length) {
      boolean isStamped = false;
      for (int i = 0; i <= targetCharArray.length - stamp.length(); ++i) {
        if (stamped[i])
          continue;
        int stampified = stampify(stamp, targetCharArray, i);
        if (stampified == 0)
          continue;
        stampedCount += stampified;
        isStamped = true;
        stamped[i] = true;
        ans.add(i);
      }
      if (!isStamped)
        return new int[] {};
    }

    Collections.reverse(ans);

    return ans.stream().mapToInt(i -> i).toArray();
  }

  private int stampify(final String stamp, char[] targetCharArray, int s) {
    int stampified = stamp.length();

    for (int i = 0; i < stamp.length(); ++i)
      if (targetCharArray[s + i] == '*')
        --stampified;
      else if (targetCharArray[s + i] != stamp.charAt(i))
        return 0;

    Arrays.fill(targetCharArray, s, s + stamp.length(), '*');

    return stampified;
  }
}