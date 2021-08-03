#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int len = s.size();
    if (len <= 1)
      return s;
    int start = 0;
    int end = 0;
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for (int i = 0; i < len; i++) {
      dp[i][i] = 1;
      if (i < len - 1 && s[i] == s[i+1]) {
        start = i;
        end = start + 1;
        dp[i][i+1] = 1;
      }
    }
    for (int sub_len = 3; sub_len <= len; sub_len++) {
      for (int i = 0; i + sub_len - 1 < len; i++) {
        int j = i + sub_len - 1;
        if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
          start = i;
          end = start + sub_len - 1;
          dp[i][j] = 1;
        }
      }
    }
    return s.substr(start, end - start + 1);
  }
};

int main() {

}
