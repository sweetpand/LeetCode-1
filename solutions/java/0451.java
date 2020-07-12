class Solution {
  public String frequencySort(String s) {
    String ans = "";
    List<Character>[] bucket = new List[s.length() + 1];
    int[] count = new int[128];

    for (char c : s.toCharArray())
      ++count[c];

    for (int i = 0; i < count.length; ++i) {
      int freq = count[i];
      if (freq > 0) {
        if (bucket[freq] == null)
          bucket[freq] = new ArrayList<>();
        bucket[freq].add((char) i);
      }
    }

    for (int freq = bucket.length - 1; freq >= 0; --freq)
      if (bucket[freq] != null)
        for (Character c : bucket[freq])
          for (int i = 0; i < freq; ++i)
            ans += c;

    return ans;
  }
}