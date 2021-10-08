class Solution {
public:
  int myAtoi(string s) {
    string tmpStr;
    int ans = 0;
    bool startCount = false;
    bool negative = false;
    bool ignoreZero = true;
    for (const auto &ch : s) {
      if (!startCount) {
        if (ch == ' ') {
          continue;
        } else if (ch == '-') {
          startCount = true;
          negative = true;
          continue;
        } else if (ch == '+') {
          startCount = true;
          continue;
        } else if (ch > '0' && ch <= '9') {
          tmpStr += ch;
          ans = ch - '0';
          startCount = true;
          ignoreZero = false;
          continue;
        } else if (ch == '0') {
          startCount = true;
          continue;
        } else {
          break;
        }
      } else if (ch == '0' && ignoreZero) {
        continue;
      } else if (ch < '0' || ch > '9') {
        break;
      } else {
        ignoreZero = false;
        tmpStr += ch;
        // check bound
        if (negative && tmpStr.size() == 10 && tmpStr >= string("2147483648")) {
          return INT_MIN;
        } else if (!negative && tmpStr.size() == 10 && tmpStr >= string("2147483647")) {
          return INT_MAX;
        } else if (negative && tmpStr.size() > 10) {
          return INT_MIN;
        } else if (!negative && tmpStr.size() > 10) {
          return INT_MAX;
        }
        ans = 10 * ans + (ch - '0');
      }
    }
    return negative ? -ans : ans;
  }
};
