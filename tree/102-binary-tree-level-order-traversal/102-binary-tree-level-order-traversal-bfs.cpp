class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    queue<TreeNode *> que;
    if (root == nullptr)
      return res;
    que.push(root);
    while (!que.empty()) {
      vector<int> tmp;
      int n = que.size();
      while (n--) {
        TreeNode *node = que.front();
        que.pop();
        tmp.push_back(node->val);
        if (node->left)
          que.push(node->left);
        if (node->right)
          que.push(node->right);
      }
      res.push_back(tmp);
    }
    return res;
  }
};
