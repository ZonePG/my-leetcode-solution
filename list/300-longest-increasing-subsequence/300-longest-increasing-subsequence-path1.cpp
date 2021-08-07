#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> lengthOfLIS(vector<int> &nums) {
    int max_length_id = 0;
    vector<vector<int>> path(nums.size(), vector<int>());
    for (int i = 0; i < nums.size(); i++) {
      path[i].push_back(nums[i]);
    }
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          if (path[i].size() < path[j].size() + 1) {
            path[i].clear();
            path[i].insert(path[i].begin(), path[j].begin(), path[j].end());
            path[i].push_back(nums[i]);
            if (path[i].size() > path[max_length_id].size()) {
              max_length_id = i;
            }
          }
        }
      }
    }

    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < path[i].size(); j++) {
        cout << path[i][j] << " ";
      }
      cout << endl;
    }

    return path[max_length_id];
  }
};

int main() {
  vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
  Solution solution;
  auto res = solution.lengthOfLIS(nums);
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
}
