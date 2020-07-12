class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> count(26, 0);

    for (const char task : tasks)
      ++count[task - 'A'];

    const int maxFreq = *max_element(begin(count), end(count));
    int ans = (maxFreq - 1) * (n + 1);

    ans += count_if(begin(count), end(count),
                    [maxFreq](int freq) { return freq == maxFreq; });

    return max(ans, (int)tasks.size());
  }
};