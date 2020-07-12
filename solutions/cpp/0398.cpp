class Solution {
 public:
  Solution(vector<int>& nums) : nums(move(nums)) {
    srand(time(nullptr));
  }

  int pick(int target) {
    int res = -1;
    int range = 0;

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == target && rand() % ++range == 0)
        res = i;

    return res;
  }

 private:
  vector<int> nums;
};