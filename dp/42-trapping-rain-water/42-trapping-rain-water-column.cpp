#include <algorithm>
#include <vector>

using namespace std;

class Solution {

public:
  int trap(vector<int> &height) {
    int sum = 0;
    for (int i = 1; i < height.size() - 1; i++) {
      int left = *max_element(height.begin(), height.begin() + i);
      int right = *max_element(height.begin() + i + 1, height.end());
      if (left > height[i] && right > height[i]) {
        sum += min(left, right) - height[i];
      }
    }
    return sum;
  }
};

int main() {}
