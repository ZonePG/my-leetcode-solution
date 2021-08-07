#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {

public:
  int trap(vector<int> &height) {
    int sum = 0;
    vector<int> left_max(height.size(), 0);
    vector<int> right_max(height.size(), 0);
    for (int i = 1; i < left_max.size(); i++) {
      left_max[i] = max(left_max[i - 1], height[i - 1]);
    }
    for (int i = height.size() - 2; i >= 0; i--) {
      right_max[i] = max(right_max[i + 1], height[i + 1]);
    }
    for (int i = 1; i < height.size() - 1; i++) {
      int left = left_max[i];
      int right = right_max[i];
      if (left > height[i] && right > height[i]) {
        sum += min(left, right) - height[i];
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
