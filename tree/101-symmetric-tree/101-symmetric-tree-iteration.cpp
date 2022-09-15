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
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        que.push(root);
        while (!que.empty()) {
            TreeNode *u = que.front();
            que.pop();
            TreeNode *v = que.front();
            que.pop();
            if (u == nullptr && v == nullptr) {
                continue;
            } else if (u == nullptr || v == nullptr || u->val != v->val) {
                return false;
            }
            que.push(u->left);
            que.push(v->right);

            que.push(u->right);
            que.push(v->left);
        }
        return true;
    }
};
