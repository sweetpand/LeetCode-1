class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    deque<int> maxQueue;

    for (int i = 0; i < nums.size(); ++i) {
      while (!maxQueue.empty() && maxQueue.back() < nums[i])
        maxQueue.pop_back();
      maxQueue.push_back(nums[i]);
      if (i >= k - 1) {
        ans.push_back(maxQueue.front());
        if (nums[i - k + 1] == maxQueue.front())
          maxQueue.pop_front();
      }
    }

    return ans;
  }
};