/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  struct Status {
    int val;
    ListNode *node;
    bool operator < (const Status &rhs) const {
      return val > rhs.val;
    }
  };
  priority_queue<Status> priority_que;

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    for (auto &node : lists) {
      if (node) {
        priority_que.push({node->val, node});
      }
    }
    ListNode *dummyNode = new ListNode(0);
    ListNode *tail = dummyNode;

    while (!priority_que.empty()) {
      Status insert_status = priority_que.top();
      priority_que.pop();
      tail->next = insert_status.node;
      tail = tail->next;
      if (insert_status.node->next) {
        priority_que.push({insert_status.node->next->val, insert_status.node->next});
      }
    }
    return dummyNode->next;
  }
};
