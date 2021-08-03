#include <string>
#include <vector>

using namespace std;

class Solution {
  int expandAroundCenter(string s, int left, int right) {
    while (left >= 0 && right < s.size() && (s[left] == s[right])) {
      left--;
      right++;
    }
    return right - left - 1;
  }
public:
  string longestPalindrome(string s) {
    int len = s.size();
    if (len <= 1)
      return s;
    int start = 0;
    int end = 0;
    for (int i = 0; i < len; i++) {
      int len1 = expandAroundCenter(s, i, i);
      int len2 = expandAroundCenter(s, i, i + 1);
      int len = len1 < len2 ? len2 : len1;
      if (len > end - start + 1) {
        start = i - (len - 1) / 2;
        end = i + len / 2;
      }
    }
    return s.substr(start, end - start + 1);
  }
};

int main() {

}
