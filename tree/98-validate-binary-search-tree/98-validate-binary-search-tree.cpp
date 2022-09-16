
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool isValidBST_helper(TreeNode *node, long long lower, long long upper) {
        if (node == nullptr) {
            return true;
        }
        
        if (node->val <= lower || node->val >= upper) {
            return false;
        }

        return isValidBST_helper(node->left, lower, node->val) && isValidBST_helper(node->right, node->val, upper);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBST_helper(root, LONG_MIN, LONG_MAX);
    }
};
