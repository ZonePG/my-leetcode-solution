#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; i++) {
      dp[i][0] = i;
    }
    for (int j = 1; j <= len2; j++) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        int case1 = dp[i - 1][j] + 1;
        int case2 = dp[i][j - 1] + 1;
        int case3 = dp[i - 1][j - 1];
        if (word1[i-1] != word2[j-1]) {
          case3 += 1;
        }
        dp[i][j] = min(case1, min(case2, case3));
      }
    }

    return dp[len1][len2];
  }
};

int main() {
  string word1("horse");
  string word2("ros");
  Solution solution;
  solution.minDistance(word1, word2);
}
