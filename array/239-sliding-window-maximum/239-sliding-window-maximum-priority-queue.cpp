#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
     vector<int> ans;
     priority_queue<pair<int, int> > q;
     for (int i = 0; i < k; i++) {
        q.push(pair<int, int>(nums[i], i));
     }
     ans.push_back(q.top().first);
     for (int i = k; i < nums.size(); i++) {
        q.push(pair<int, int>(nums[i], i));
        while (q.top().second + k <= i) {
          q.pop();
        }
        ans.push_back(q.top().first);
     }
     return ans;
  }
};
