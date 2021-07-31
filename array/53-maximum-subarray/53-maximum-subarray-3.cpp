class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int sum = 0;
      int res = nums[0];
      int resLeft = 0;
      int resRight = 0;
      int left = 0;
      for (int i = 0; i < nums.size(); i++) {
        if (sum > 0) {
          sum += nums[i];
        } else {
          sum = nums[i];
          left = i;
        }

        if (sum > res) {
          resLeft = left;
          resRight = i;
          res = sum;
        }
      }

      cout << resLeft << endl;
      cout << resRight << endl;
      return res;
    }
};
