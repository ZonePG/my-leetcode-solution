#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> res;
      if (matrix.size() == 0)
        return res;
      int up = 0, left = 0;
      int down = matrix.size() - 1;
      int right = matrix[0].size() - 1;
      int count = (right + 1) * (down + 1);
      while (up <= down && left <= right) {
        for (int j = left; j <= right && count >= 1; j++) {
          res.push_back(matrix[up][j]);
          count--;
        }
        for (int i = up + 1; i <= down && count >= 1; i++) {
          res.push_back(matrix[i][right]);
          count--;
        }
        for (int j = right - 1; j >= left && count >= 1; j--) {
          res.push_back(matrix[down][j]);
          count--;
        }
        for (int i = down - 1; i >= up + 1 && count >= 1; i--) {
          res.push_back(matrix[i][left]);
          count--;
        }
        left++;
        up++;
        right--;
        down--;
      }
      return res;
    }
};

int main() {
  Solution solution;
  vector<int> a = {1, 2, 3};
  vector<int> b = {4, 5, 6};
  vector<int> c = {7, 8, 9};
  vector<vector<int>> matrix;
  matrix.push_back(a);
  matrix.push_back(b);
  matrix.push_back(c);
  solution.spiralOrder(matrix);
}
