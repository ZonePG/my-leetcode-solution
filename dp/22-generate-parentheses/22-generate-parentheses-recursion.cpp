#include <vector>
#include <string>
using namespace std;

class Solution {
  vector<string> ans;

  void dfs(string path, const int &n, int lc, int rc) {
    if (rc > lc || lc > n || rc > n) {
      return;
    }

    if (rc == lc && rc == n) {
      ans.push_back(path);
    }

    dfs(path + "(", n, lc + 1, rc);
    dfs(path + ")", n, lc, rc + 1);
  }

public:
  vector<string> generateParenthesis(int n) {
    dfs("", n, 0, 0);
    return ans;
  }
};
