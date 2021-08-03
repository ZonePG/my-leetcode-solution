#include <vector>

using namespace std;

class Solution {
  void dfs(vector<vector<char>> &grid, vector<vector<bool>> &flag, int i,
           int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        (flag[i][j] == true) || (grid[i][j] == '0'))
      return;
    flag[i][j] = true;
    dfs(grid, flag, i + 1, j);
    dfs(grid, flag, i - 1, j);
    dfs(grid, flag, i, j + 1);
    dfs(grid, flag, i, j - 1);
    return;
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty()) {
      return 0;
    }
    int count = 0;
    vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size(), false));
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (!flag[i][j] && grid[i][j] == '1') {
          dfs(grid, flag, i, j);
          count++;
        }
      }
    }
    return count;
  }
};

int main() {
  Solution solution;

}
