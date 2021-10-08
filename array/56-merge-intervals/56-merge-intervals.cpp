class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> ans;
    if (intervals.size() == 0) {
      return ans;
    }

    sort(intervals.begin(), intervals.end());

    ans.emplace_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      vector<int> &ans_back = ans.back();
      if (ans_back[1] >= intervals[i][0] && ans_back[1] <= intervals[i][1]) {
        ans_back[1] = intervals[i][1];
      } else if (ans_back[1] < intervals[i][0]) {
        ans.emplace_back(intervals[i]);
      }
    }

    return ans;
  }
};
