class Solution {
  vector<vector<int>> res;
  vector<int> tmp;
  void permute_res(vector<int> &nums, vector<int> &flag) {
    if (tmp.size() == nums.size()) {
      res.push_back(tmp);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (flag[i] == 0) {
        tmp.push_back(nums[i]);
        flag[i] = 1;
        permute_res(nums, flag);
        tmp.pop_back();
        flag[i] = 0;
      }
    }
  }
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<int> flag(nums.size(), 0);
    permute_res(nums, flag);
    return res;
  }
};
