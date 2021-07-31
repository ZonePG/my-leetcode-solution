class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    vector<int> res(2, 0);
    for (int i = 0; i < nums.size(); i++) {
      if (map.count(target - nums[i])) {
        res[0] = i;
        res[1] = map[target - nums[i]];
      }
      map[nums[i]] = i;
    }
    return res;
  }
};
