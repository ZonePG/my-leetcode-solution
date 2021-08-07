#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int max_height = *max_element(height.begin(), height.end());
    int sum = 0;
    for (int i = 1; i <= max_height; i++) {
      bool isStart = false;
      int temp_sum = 0;
      for (int j = 0; j < height.size(); j++) {
        if (height[j] >= i) {
          isStart = true;
          sum += temp_sum;
          temp_sum = 0;
        }
        if (isStart && height[j] < i) {
          temp_sum++;
        }
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
