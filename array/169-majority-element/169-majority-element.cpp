#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = -1;
        int count = 0;
        for (const int &num : nums) {
            if (candidate == num) {
                ++count;
            } else if (--count < 0) {
                candidate = num;
                count = 1;
            }
        }
        return candidate;
    }
};
