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
  vector<int> res;

  void traversal(TreeNode *node) {
    if (node == nullptr) {
      return ;
    }
    
    res.push_back(node->val);
    traversal(node->left);
    traversal(node->right);
  }

public:
  vector<int> preorderTraversal(TreeNode *root) {
    traversal(root);
    return res;
  }
};
