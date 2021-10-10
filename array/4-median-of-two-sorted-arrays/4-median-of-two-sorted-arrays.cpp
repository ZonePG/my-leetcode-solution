#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size();
    int n = nums2.size();

    if (m > n) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int LMax1, RMin1;
    int LMax2, RMin2;
    int cut1, cut2;
    int low = 0, high = 2 * m;

    while (low <= high) {
      cut1 = (low + high) / 2;
      cut2 = m + n - cut1;

      LMax1 = (cut1 == 0) ? INT_MIN : nums1[(cut1 - 1) / 2];
      RMin1 = (cut1 == 2 * m) ? INT_MAX : nums1[cut1 / 2];
      LMax2 = (cut2 == 0) ? INT_MIN : nums2[(cut2 - 1) / 2];
      RMin2 = (cut2 == 2 * n) ? INT_MAX : nums2[cut2 / 2];

      if (LMax1 > RMin2) {
        high = cut1 - 1;
      } else if (LMax2 > RMin1) {
        low = cut1 + 1;
      } else {
        break;
      }
    }
    return (max(LMax1, LMax2) + min(RMin1, RMin2)) / 2.0;
  }
};

int main() {
  std::vector<int> nums1 = {1, 3};
  std::vector<int> nums2 = {2};
  Solution soution;
  int value = soution.findMedianSortedArrays(nums1, nums2);
  return 0;
}
