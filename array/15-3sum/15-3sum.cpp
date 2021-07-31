class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    if (nums.size() < 3) {
      return ans;
    }
    for (int i = 0; i < nums.size() - 2; i++) {
      if (i != 0 && (nums[i] == nums[i - 1]))
        continue;
      int j = i + 1;
      int k = nums.size() - 1;
      while (j != k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum > 0) {
          k--;
        } else if (sum < 0) {
          j++;
        } else {
          vector<int> tmp;
          tmp.push_back(nums[i]);
          tmp.push_back(nums[j]);
          tmp.push_back(nums[k]);
          ans.push_back(tmp);
          j++;
          while (nums[j] == nums[j - 1] && j < k)
            j++;
        }
      }
    }
    return ans;
  }
};
