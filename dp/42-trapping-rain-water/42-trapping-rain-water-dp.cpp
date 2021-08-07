#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
  int trap(vector<int> &height) {
    int sum = 0;
    int left = 0, right = height.size() - 1;
    int left_max = 0;
    int right_max = 0;
    while (left < right) {
      if (height[left] < height[right]) {
        if (height[left] > left_max) {
          left_max = height[left];
        } else {
          sum += left_max - height[left];
        }
        left++;
      } else {
        if (height[right] > right_max) {
          right_max = height[right];
        } else {
          sum += right_max - height[right];
        }
        right--;
      }
    }

    return sum;
  }
};

int main() {
  vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  Solution solution;
  cout << solution.trap(height) << endl;
}
