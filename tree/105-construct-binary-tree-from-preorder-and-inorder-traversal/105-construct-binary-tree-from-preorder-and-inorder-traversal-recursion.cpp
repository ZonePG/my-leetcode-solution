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
  unordered_map<int, int> index;
  TreeNode *build(vector<int> &preorder, vector<int> &inorder, int preLeft,
                  int preRight, int inLeft, int inRight) {
    if (preLeft > preRight) {
      return nullptr;
    }

    int preRoot = preLeft;
    int inRoot = index[preorder[preRoot]];

    TreeNode *root = new TreeNode(preorder[preRoot]);
    int leftSize = inRoot - inLeft;
    root->left = build(preorder, inorder, preLeft + 1, preLeft + leftSize, inLeft, inRoot - 1);
    root->right = build(preorder, inorder, preLeft + leftSize + 1, preRight, inRoot + 1, inRight);
    return root;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < preorder.size(); i++) {
      index[inorder[i]] = i;
    }
    return build(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
  }
};
