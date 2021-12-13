#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Solution {
  vector<string> ans;
  vector<string> temp;
  void dfs(const string &s, int start) {
    if (start == s.size() && temp.size() == 4) {
      string str = temp[0];
      for (int i = 1; i <= 3; i++) {
        str += "." + temp[i];
      }
      ans.push_back(str);
      return;
    }

    if (start < s.size() && temp.size() == 4) {
      return;
    }

    for (int len = 1; len <= 3; len++) {
      if (start >= s.size()) {
        return;
      }
      if (len != 1 && s[start] == '0') {
        return;
      }
      string str = s.substr(start, len);
      if (len == 3 && atoi(str.c_str()) > 255) {
        return;
      }
      temp.push_back(str);
      dfs(s, start + len);
      temp.pop_back();
    }
  }

public:
  vector<string> restoreIpAddresses(string s) {
    dfs(s, 0);
    return ans;
  }
};
