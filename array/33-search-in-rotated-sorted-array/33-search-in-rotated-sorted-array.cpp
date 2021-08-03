#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = 0;
    for (; right + 1 < nums.size(); right++) {
      if (nums[right + 1] < nums[right])
        break;
    }
    if (nums[left] > target) {
      left = right + 1;
      right = nums.size() - 1;
    }

    int mid = (left + right) / 2;
    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return -1;
  }
};

int main() {
  Solution solution;
  vector<int> s {3, 1};
  solution.search(s, 1);
}
