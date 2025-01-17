class Solution {
  public int rotatedDigits(int N) {
    int ans = 0;

    for (int i = 1; i <= N; ++i)
      if (isGoodNumber(i))
        ++ans;

    return ans;
  }

  private boolean isGoodNumber(int i) {
    boolean isRotated = false;

    for (char c : String.valueOf(i).toCharArray()) {
      if (c == '0' || c == '1' || c == '8')
        continue;
      if (c == '2' || c == '5' || c == '6' || c == '9')
        isRotated = true;
      else
        return false;
    }

    return isRotated;
  }
}