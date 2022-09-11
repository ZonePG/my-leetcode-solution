#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> res(len1 + len2, 0);
        for (int i = len1 - 1; i >= 0; --i) {
            int n1 = num1[i] - '0';
            for (int j = len2 - 1; j >= 0; --j) {
                int n2 = num2[j] - '0';
                int sum = res[i + j + 1] + n1 * n2;
                res[i + j + 1] = sum % 10;
                res[i + j] += sum / 10;
            }
        }
        string res_str = "";
        for (int i = 0; i < res.size(); ++i) {
            char tmp = res[i] + '0';
            if (res_str.empty() && tmp == '0') {
                continue;
            } else {
                res_str += tmp;
            }
        }
        return res_str;
    }
};
