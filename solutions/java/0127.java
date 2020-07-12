class Solution {
  public int ladderLength(String beginWord, String endWord, List<String> wordList) {
    Set<String> set = new HashSet<>(wordList);

    if (!set.contains(endWord))
      return 0;

    int ans = 0;

    Set<String> set1 = new HashSet<>(Arrays.asList(beginWord));
    Set<String> set2 = new HashSet<>(Arrays.asList(endWord));

    while (!set1.isEmpty() && !set2.isEmpty()) {
      ++ans;
      if (set1.size() > set2.size())
        swap(set1, set2);
      Set<String> tempSet = new HashSet<>();
      for (String word : set1) {
        char[] charArray = word.toCharArray();
        for (int i = 0; i < word.length(); ++i) {
          char c = charArray[i];
          for (char j = 'a'; j <= 'z'; ++j) {
            charArray[i] = j;
            String newWord = String.valueOf(charArray);
            if (set2.contains(newWord))
              return ans + 1;
            if (!set.contains(newWord))
              continue;
            set.remove(newWord);
            tempSet.add(newWord);
          }
          charArray[i] = c;
        }
      }
      set1 = tempSet;
    }

    return 0;
  }

  private void swap(Set s1, Set s2) {
    Set temp = s1;
    s1 = s2;
    s2 = temp;
  }
}