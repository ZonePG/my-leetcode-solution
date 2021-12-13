#include <vector>
#include <deque>
#include <utility>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    deque<int> q;
    for (int i = 0; i < k; i++) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
    }

    vector<int> ans;
    ans.push_back(nums[q.front()]);
    for (int i = k; i < nums.size(); i++) {
      while (!q.empty() && nums[i] >= nums[q.back()]) {
        q.pop_back();
      }
      q.push_back(i);
      while (q.front() + k <= i) {
        q.pop_front();
      }
      ans.push_back(nums[q.front()]);
    }
    return ans;
  }
};
