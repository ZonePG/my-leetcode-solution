class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr)
      return res;
    queue<TreeNode*> que;
    bool left = 1;
    que.push(root);
    while (!que.empty()) {
      int n = que.size();
      deque<int> levelList;
      while (n--) {
        TreeNode *node = que.front();
        que.pop();
        if (left) {
          levelList.push_back(node->val);
        } else {
          levelList.push_front(node->val);
        }
        if (node->left) {
          que.push(node->left);
        }
        if (node->right) {
          que.push(node->right);
        }
      }
      left = !left;
      res.push_back(vector<int>{levelList.begin(), levelList.end()});
    }
    return res;
  }
};
