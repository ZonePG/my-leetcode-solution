class Solution {
public:
  string addStrings(string num1, string num2) {
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int cr = 0;
    string ans = "";
    while (i >= 0 || j >= 0 || cr != 0) {
      int x = i >= 0 ? num1[i] - '0' : 0;
      int y = j >= 0 ? num2[j] - '0' : 0;
      int result = x + y + cr;
      ans.insert(0, 1, '0' + result % 10);
      cr = result / 10;
      i--; j--;
    }
    return ans;
  }
};
