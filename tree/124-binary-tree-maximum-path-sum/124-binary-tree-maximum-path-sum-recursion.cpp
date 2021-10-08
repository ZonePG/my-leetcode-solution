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
  int maxSum = INT_MIN;

  int maxGain(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }

    int leftGain = max(maxGain(node->left), 0);
    int rightGain = max(maxGain(node->right), 0);

    int value = leftGain + rightGain + node->val;

    maxSum = max(maxSum, value);

    return node->val + max(leftGain, rightGain);
  }

public:
  int maxPathSum(TreeNode *root) {
    maxGain(root);
    return maxSum;
  }
};
