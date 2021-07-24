class Solution {
public:
  int findKthLargest(vector<int> &nums, int k) {
    // solution 1
    /* sort(nums.begin(), nums.end(), greater<int>()); */
    /* return nums[k - 1]; */

    // solution 2
    priority_queue<int, vector<int>> big_heap;
    for (int i = 0; i < nums.size(); i++) {
      big_heap.push(nums[i]);
    }
    for (int i = 0; i < k - 1; i++) {
      big_heap.pop();
    }
    return big_heap.top();
  }
};
