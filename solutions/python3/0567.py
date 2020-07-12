class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        count1 = collections.Counter(s1)
        required = len(s1)

        for r, c in enumerate(s2):
            count1[c] -= 1
            if count1[c] >= 0:
                required -= 1
            if r >= len(s1):
                count1[s2[r - len(s1)]] += 1
                if count1[s2[r - len(s1)]] > 0:
                    required += 1
            if required == 0:
                return True

        return False
