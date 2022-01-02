#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> dp; 
    vector<string> dp0;
    dp0.push_back("");
    dp.push_back(dp0);

    for (int i = 1; i <= n; i++) {
      vector<string> tmp;
      for (int j = 0; j < i; j++) {
        for (const auto &s1 : dp[j]) {
          for (const auto &s2 : dp[i - 1 - j]) {
            tmp.push_back("(" + s1 + ")" + s2);
          }
        }
      }
      dp.push_back(tmp);
    }

    return dp[n];
  }
};
