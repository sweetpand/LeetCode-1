class Solution {
  public int numUniqueEmails(String[] emails) {
    Set<String> seen = new HashSet<>();

    for (final String email : emails) {
      String[] parts = email.split("@");
      String[] local = parts[0].split("\\+");
      seen.add(local[0].replace(".", "") + "@" + parts[1]);
    }

    return seen.size();
  }
}