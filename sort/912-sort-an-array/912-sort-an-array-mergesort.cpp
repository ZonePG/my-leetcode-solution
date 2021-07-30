class Solution {
  vector<int> tmp;

  void mergeSort(vector<int> &nums, int left, int right) {
    if (left >= right)
      return;
    int mid = (left + right) >> 1;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    int i = left, j = mid + 1;
    int cnt = 0;
    while (i <= mid && j <= right) {
      if (nums[i] <= nums[j]) {
        tmp[cnt++] = nums[i++];
      } else {
        tmp[cnt++] = nums[j++];
      }
    }
    while (i <= mid) {
      tmp[cnt++] = nums[i++];
    }
    while (j <= right) {
      tmp[cnt++] = nums[j++];
    }
    for (int i = 0; i < right - left + 1; i++) {
      nums[i + left] = tmp[i];
    }
  }

public:
  vector<int> sortArray(vector<int> &nums) {
    tmp.resize(nums.size(), 0);
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }
};
