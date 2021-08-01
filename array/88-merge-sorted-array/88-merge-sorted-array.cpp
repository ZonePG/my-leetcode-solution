class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> sorted;
    int i = 0, j = 0;
    while (i < m && j < n) {
      if (nums1[i] <= nums2[j]) {
        sorted.push_back(nums1[i]);
        i++;
      } else {
        sorted.push_back(nums2[j]);
        j++;
      }
    }
    while (i < m) {
      sorted.push_back(nums1[i]);
      i++;
    }
    while (j < n) {
      sorted.push_back(nums2[j]);
      j++;
    }
    for (i = 0; i < m + n; i++) {
      nums1[i] = sorted[i];
    }
  }
};
