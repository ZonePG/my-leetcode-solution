class Solution {
  void maxHeapify(vector<int>& nums, int i, int len) {
    for (; (i << 1)  + 1 <= len; ) {
      int left_son = (i << 1) + 1;
      int right_son = (i << 1) + 2;
      int large;
      if (left_son <= len && nums[left_son] > nums[i]) {
        large = left_son;
      } else {
        large = i;
      }
      if (right_son <= len && nums[right_son] > nums[large]) {
        large = right_son;
      }
      if (large != i) {
        swap(nums[i], nums[large]);
        i = large;
      } else {
        break;
      }
    }
  }

  void buildMaxHeap(vector<int>& nums, int len) {
    for (int i = (len - 1) / 2; i >= 0; i--) {
      maxHeapify(nums, i, len);
    }
  }

  void heapSort(vector<int>& nums) {
    int len = nums.size() - 1;
    buildMaxHeap(nums, len);
    for (int i = len; i >= 1; --i) {
      swap(nums[i], nums[0]);
      len--;
      maxHeapify(nums, 0, len);
    }
  }

public:
  vector<int> sortArray(vector<int> &nums) {
    heapSort(nums);
    return nums;
  }
};
