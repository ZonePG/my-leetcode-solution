class Solution {
  int partition(vector<int>& nums, int left, int right) {
    int mid = nums[right];
    int i = left;
    for (int j = left; j <= right - 1; j++) {
      if (nums[j] < mid) {
        swap(nums[i], nums[j]);
        i = i + 1;
      }
    }
    swap(nums[i], nums[right]);
    return i;
  }

  int randomized_partition(vector<int>& nums, int left, int right) {
    int i = rand() % (right - left + 1) + left;
    swap(nums[right], nums[i]);
    return partition(nums, left, right);
  }

  void randomized_quicksort(vector<int>& nums, int left, int right) {
    if (left < right) {
      int pos = randomized_partition(nums, left, right);
      randomized_quicksort(nums, left, pos - 1);
      randomized_quicksort(nums, pos + 1, right);
    }
  }

public:
  vector<int> sortArray(vector<int> &nums) {
    srand((unsigned)time(NULL));
    randomized_quicksort(nums, 0, nums.size() - 1);
    return nums;
  }
};
