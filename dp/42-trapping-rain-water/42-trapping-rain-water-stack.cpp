#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    int sum = 0;
    stack<int> stk;
    for (int i = 0; i < height.size(); i++) {
      if (!stk.empty() && height[i] < height[stk.top()]) {
        stk.push(i);
      } else if (!stk.empty() && height[i] == height[stk.top()]) {
        stk.pop();
        stk.push(i);
      } else {
        while (!stk.empty() && height[i] > height[stk.top()]) {
          int mid_h = height[stk.top()];
          stk.pop();
          if (stk.empty()) {
            break;
          }
          int w = i - stk.top() - 1;
          int h = min(height[i], height[stk.top()]) - mid_h;
          sum += w * h;
        }
        stk.push(i);
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
