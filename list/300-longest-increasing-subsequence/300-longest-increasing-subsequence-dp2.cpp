#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> tail;
    tail.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] > tail.back()) {
        tail.push_back(nums[i]);
      } else if (nums[i] < tail.back()) {
        // binary search
        int left = 0, right = tail.size() - 1;
        int mid;
        while (left <= right) {
          mid = (left + right + 1) / 2;
          if (tail[mid] < nums[i]) {
            left = mid + 1;
          } else if (tail[mid] > nums[i]) {
            right = mid - 1;
          } else {
            break;
          }
        }
        // important
        if (left > right) {
          tail[left] = nums[i];
        }
      }
    }
    return tail.size();
  }
};

int main() {
  vector<int> nums {10,9,2,5,3,4};
  Solution solution;
  solution.lengthOfLIS(nums);
}
