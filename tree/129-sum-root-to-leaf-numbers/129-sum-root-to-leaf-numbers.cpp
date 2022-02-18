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
  int dfs(TreeNode *node, int pre_sum) {
    if (node == nullptr) {
      return 0;
    }

    int sum = pre_sum * 10 + node->val;
    if (!node->left && !node->right) {
      return sum;
    } else {
      return dfs(node->left, sum) + dfs(node->right, sum);
    }
  }

public:
  int sumNumbers(TreeNode *root) { return dfs(root, 0); }
};
