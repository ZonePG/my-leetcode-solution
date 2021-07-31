class Solution {
public:
  vector<vector<int>> res;
  void level(TreeNode*root, int lev) {
    if (root == nullptr)
      return;
    if (lev >= res.size()) {
      res.push_back(vector<int>());
    }
    res[lev].push_back(root->val);
    level(root->left, lev + 1);
    level(root->right, lev + 1);
  }

  vector<vector<int>> levelOrder(TreeNode *root) {
    level(root, 0);
    return res;
  }
};
