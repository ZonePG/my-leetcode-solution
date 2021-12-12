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
  int max_depth{0};
  void preorder(TreeNode *node, int depth) {
    if (node == nullptr) {
      return;
    }
    max_depth = max(depth, max_depth);
    preorder(node->left, depth + 1);
    preorder(node->right, depth + 1);
  }
public:
  int maxDepth(TreeNode *root) {
    preorder(root, 1);
    return max_depth;
  }
};
