class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int sum = 0;
      int res = nums[0];
      for (int i = 0; i < nums.size(); i++) {
        sum = sum > 0 ? (sum + nums[i]) : nums[i];
        res = max(sum, res);
      }
      return res;
    }
};
