class Solution {
  public List<String> removeComments(String[] source) {
    List<String> ans = new ArrayList<>();
    boolean commenting = false;
    String modified = "";

    for (final String line : source) {
      for (int i = 0; i < line.length();) {
        if (i + 1 == line.length()) {
          if (!commenting)
            modified += line.charAt(i);
          ++i;
          break;
        }
        String twoChars = line.substring(i, i + 2);
        if (twoChars.equals("/*") && !commenting) {
          commenting = true;
          i += 2;
        } else if (twoChars.equals("*/") && commenting) {
          commenting = false;
          i += 2;
        } else if (twoChars.equals("//")) {
          if (!commenting)
            break;
          else
            i += 2;
        } else {
          if (!commenting)
            modified += line.charAt(i);
          ++i;
        }
      }
      if (modified.length() > 0 && !commenting) {
        ans.add(modified);
        modified = "";
      }
    }

    return ans;
  }
}