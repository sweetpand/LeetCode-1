struct UglyNum {
  int prime;
  int index;
  int value = prime * index;
};

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    const int k = primes.size();

    auto compare = [](const UglyNum& a, UglyNum& b) {
      return a.value > b.value;
    };
    priority_queue<UglyNum, vector<UglyNum>, decltype(compare)> pq(compare);

    for (const int prime : primes)
      pq.push({prime, 1, prime});

    vector<int> uglyNums{1};

    while (uglyNums.size() < n) {
      uglyNums.push_back(pq.top().value);
      while (pq.top().value == uglyNums.back()) {
        const auto [prime, index, value] = pq.top(); pq.pop();
        pq.push({prime, index + 1, prime * uglyNums[index]});
      }
    }

    return uglyNums.back();
  }
};