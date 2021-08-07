#include <iostream>

class Solution {
public:
  int climbStairs(int n) {
    if (n <= 2)
      return n;
    int res;
    int tmp1 = 1;
    int tmp2 = 2;
    for (int i = 3; i <= n; i++) {
      res = tmp1 + tmp2;
      tmp1 = tmp2;
      tmp2 = res;
    }
    return res;
  }
};

int main() {
}
