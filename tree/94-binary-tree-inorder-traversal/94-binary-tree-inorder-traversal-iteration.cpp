#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode*> nodeStack;
    while (root != nullptr || !nodeStack.empty()) {
      while (root != nullptr) {
        nodeStack.push(root);
        root = root->left;
      }
      root = nodeStack.top();
      nodeStack.pop();
      res.push_back(root->val);
      root = root->right;
    }
    return res;
  }
};

int main() {

}
