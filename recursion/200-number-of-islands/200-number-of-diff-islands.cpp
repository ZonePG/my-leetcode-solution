#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
  unordered_set<string> set;

  void dfs(vector<vector<char>> &grid, vector<vector<bool>> &flag, int i,
           int j, int baseX, int baseY, string &s) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() ||
        (flag[i][j] == true) || (grid[i][j] == '0'))
      return;
    flag[i][j] = true;
    s += to_string(i - baseX) + "_" + to_string(j - baseY) + "_";
    dfs(grid, flag, i + 1, j, baseX, baseY, s);
    dfs(grid, flag, i - 1, j, baseX, baseY, s);
    dfs(grid, flag, i, j + 1, baseX, baseY, s);
    dfs(grid, flag, i, j - 1, baseX, baseY, s);
    return;
  }

public:
  int numIslands(vector<vector<char>> &grid) {
    if (grid.empty()) {
      return 0;
    }
    vector<vector<bool>> flag(grid.size(), vector<bool>(grid[0].size(), false));
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (!flag[i][j] && grid[i][j] == '1') {
          string s;
          dfs(grid, flag, i, j, i, j, s);
          set.insert(s);
        }
      }
    }
    return set.size();
  }
};

int main() {
  Solution solution;

}
