# Sliding window

### 3. Longest Substring Without Repeating Characters

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ans = 0
        count = collections.Counter()

        l = 0
        for r, c in enumerate(s):
            count[c] += 1
            while count[c] > 1:
                count[s[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)

        return ans
```

### 76. Minimum Window Substring

```python
class Solution:
    def minWindow(self, s: str, t: str) -> str:
        count = collections.Counter(t)
        required = len(t)
        bestLeft = 0
        minLength = float('inf')

        l = 0
        for r, c in enumerate(s):
            count[c] -= 1
            if count[c] >= 0:
                required -= 1
            while required == 0:
                if r - l + 1 < minLength:
                    bestLeft = l
                    minLength = r - l + 1
                count[s[l]] += 1
                if count[s[l]] > 0:
                    required += 1
                l += 1

        return '' if minLength == float('inf') else s[bestLeft:bestLeft + minLength]
```

### 424. Longest Repeating Character Replacement

```python
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        ans = 0
        maxFreq = 0
        count = collections.Counter()

        l = 0
        for r, c in enumerate(s):
            count[c] += 1
            maxFreq = max(maxFreq, count[c])
            while maxFreq + k < r - l + 1:
                count[s[l]] -= 1
                l += 1
            ans = max(ans, r - l + 1)

        return ans
```

### 438. Find All Anagrams ina String

Method 1 (similar to 424. Longest Repeating Character Replacement)

First, find the substring (sliding window) in `s`

Second, check if the window's length equals to `p`'s length

```python
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = []
        count = collections.Counter(p)
        required = len(p)

        l = 0
        for r, c in enumerate(s):
            count[c] -= 1
            if count[c] >= 0:
                required -= 1
            while required == 0:
                if r - l + 1 == len(p):
                    ans.append(l)
                count[s[l]] += 1
                if count[s[l]] > 0:
                    required += 1
                l += 1

        return ans
```

### 438. Find All Anagrams ina String

Method 2 (Similar to 567. Permutation in String)

First, fix the window's length

Second, check if `required == 0` (i.e., the window contains all characters in `s2`)

```python
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        ans = []
        count = collections.Counter(p)
        required = len(p)

        for r, c in enumerate(s):
            count[c] -= 1
            if count[c] >= 0:
                required -= 1
            if r >= len(p):
                count[s[r - len(p)]] += 1
                if count[s[r - len(p)]] > 0:
                    required += 1
            if required == 0:
                ans.append(r - len(p) + 1)

        return ans
```

### 567. Permutation in String

```python
class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        count_s1 = collections.Counter(s1)
        required = len(s1)

        for r, c in enumerate(s2):
            count_s1[c] -= 1
            if count_s1[c] >= 0:
                required -= 1
            if r >= len(s1):
                count_s1[s2[r - len(s1)]] += 1
                if count_s1[s2[r - len(s1)]] > 0:
                    required += 1
            if required == 0:
                return True

        return False
```

### 904. Fruit Into Baskets

```python
class Solution:
    def totalFruit(self, tree: List[int]) -> int:
        ans = 0
        count = collections.defaultdict(int)

        l = 0
        for r, t in enumerate(tree):
            count[t] += 1
            while len(count) > 2:
                count[tree[l]] -= 1
                if count[tree[l]] == 0:
                    del count[tree[l]]
                l += 1
            ans = max(ans, r - l + 1)

        return ans
```

### 1004. Max Consecutive Ones III

```python
class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        ans = 0

        l = 0
        for r, a in enumerate(A):
            if a == 0:
                K -= 1
            while K < 0:
                if A[l] == 0:
                    K += 1
                l += 1
            ans = max(ans, r - l + 1)

        return ans
```
