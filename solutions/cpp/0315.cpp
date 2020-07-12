struct Item {
  int value = 0;
  int index = 0;
  Item(int value, int index) : value(value), index(index) {}
  Item() : value(0), index(0) {}
};

class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    const int n = nums.size();

    vector<int> counts(n);
    vector<Item> items(n);

    for (int i = 0; i < n; ++i)
      items[i] = Item(nums[i], i);

    function<void(int, int, int)> merge = [&](int l, int m, int r) {
      vector<Item> sorted(r - l + 1);
      int k = 0;      // point to the sorted's beginning
      int i = l;      // point to the left's beginning
      int j = m + 1;  // point to the right's beginning
      int rightCount = 0;

      while (i <= m && j <= r)
        if (items[j].value < items[i].value) {
          ++rightCount;
          sorted[k++] = items[j++];
        } else {
          counts[items[i].index] += rightCount;
          sorted[k++] = items[i++];
        }

      // put possible remaining left part to the sorted array
      while (i <= m) {
        counts[items[i].index] += rightCount;
        sorted[k++] = items[i++];
      }

      // put possible remaining right part to the sorted array
      while (j <= r)
        sorted[k++] = items[j++];

      copy(begin(sorted), end(sorted), begin(items) + l);
    };

    function<void(int, int)> mergeSort = [&](int l, int r) {
      if (l >= r) return;

      const int m = l + (r - l) / 2;
      mergeSort(l, m);
      mergeSort(m + 1, r);
      merge(l, m, r);
    };

    mergeSort(0, n - 1);

    return counts;
  }
};