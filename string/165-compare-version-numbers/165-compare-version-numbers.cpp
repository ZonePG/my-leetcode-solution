#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length();
        int len2 = version2.length();
        int i = 0, j = 0;
        while (i < len1 || j < len2) {
            int v1 = 0;
            for (; i < len1 && version1[i] != '.'; ++i) {
                v1 = v1 * 10 + (version1[i] - '0');
            }
            ++i;
            int v2 = 0;
            for (; j < len2 && version2[j] != '.'; ++j) {
                v2 = v2 * 10 + (version2[j] - '0');
            }
            ++j;
            if (v1 != v2) {
                return v1 > v2 ? 1 : -1;
            }
        }
        return 0;
    }
};
