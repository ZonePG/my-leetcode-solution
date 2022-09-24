#include <vector>

using namespace std;

class Solution {

    vector<vector<int>> res;

    void dfs(vector<int> &candidates, int begin, int target, vector<int> &path) {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int i = begin; i < candidates.size(); ++i) {
            if (target - candidates[i] < 0) {
                break;
            }

            path.push_back(candidates[i]);
            dfs(candidates, i, target - candidates[i], path);
            path.pop_back();
        }
    }

  public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        if (target < 0) {
            return res;
        }

        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(candidates, 0, target, path);
        return res;
    }
};
