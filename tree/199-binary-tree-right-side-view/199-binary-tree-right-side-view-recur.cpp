class Solution {
  vector<int> res;

  void level(TreeNode *root, int lev) {
    if (root == nullptr) {
      return ;
    }
    if (lev > res.size()) {
      res.push_back(root->val);
    }
    level(root->right, lev + 1);
    level(root->left, lev + 1);
  }

public:
  vector<int> rightSideView(TreeNode *root) {
    level(root, 1);
    return res;
  }
};
