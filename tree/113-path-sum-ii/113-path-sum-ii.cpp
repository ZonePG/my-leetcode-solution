#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
  vector<vector<int>> ans;
  vector<int> path;

  void dfs(TreeNode *node, int targetSum) {
    if (node == nullptr) {
      return;
    }
    path.push_back(node->val);
    targetSum -= node->val;
    if (node->left == nullptr && node->right == nullptr && targetSum == 0) {
      ans.push_back(path);
    }
    dfs(node->left, targetSum);
    dfs(node->right, targetSum);
    path.pop_back();
  }

public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    dfs(root, targetSum);
    return ans;
  }
};
