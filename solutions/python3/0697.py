class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        ans = 0
        degree = 0
        firstSeen = {}
        numCounts = collections.defaultdict(int)

        for i, num in enumerate(nums):
            if num not in firstSeen:
                firstSeen[num] = i
            numCounts[num] += 1
            if numCounts[num] > degree:
                degree = numCounts[num]
                ans = i - firstSeen[num] + 1
            elif numCounts[num] == degree:
                ans = min(ans, i - firstSeen[num] + 1)

        return ans
