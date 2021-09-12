#include <iostream>

class Solution {
public:
  int mySqrt(int x) {
    if (x == 0)
      return 0;
    double x_i = x;
    double x_i_next = (x_i + x / x_i) / 2;
    while (fabs(x_i_next - x_i) > 1e-7) {
      x_i = x_i_next;
      x_i_next = (x_i + x / x_i) / 2;
    }
    return int(x_i_next);
  }
};

int main() {
  Solution solution;
  solution.mySqrt(8);
}
