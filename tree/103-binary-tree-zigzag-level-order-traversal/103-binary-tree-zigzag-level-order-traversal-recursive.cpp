class Solution {
  vector<vector<int>> res;
public:
  void level(TreeNode *node, int lev) {
    if (node == nullptr)
      return ;
    if (lev >= res.size())
      res.push_back(vector<int>());
    if (lev % 2 == 0) {
      res[lev].push_back(node->val);
    } else {
      res[lev].insert(res[lev].begin(), node->val);
    }
    level(node->left, lev + 1);
    level(node->right, lev + 1);
  }

  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    level(root, 0);
    return res;
  }
};

