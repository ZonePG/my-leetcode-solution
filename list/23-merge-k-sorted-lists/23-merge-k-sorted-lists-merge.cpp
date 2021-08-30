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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *dummyNode = new ListNode(0);
    ListNode *pre = dummyNode;
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    while (p1 && p2) {
      if (p1->val <= p2->val) {
        pre->next = p1;
        p1 = p1->next;
      } else {
        pre->next = p2;
        p2 = p2->next;
      }
      pre = pre->next;
    }
    if (p1) {
      pre->next = p1;
    } else if (p2) {
      pre->next = p2;
    }

    return dummyNode->next;
  }

  ListNode *merge(vector<ListNode *> &lists, int left, int right) {
    if (left == right) {
      return lists[left];
    } else if (left > right) {
      return nullptr;
    }
    int mid = (left + right) / 2;
    return mergeTwoLists(merge(lists, left, mid), merge(lists, mid + 1, right));
  }

public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    return merge(lists, 0, lists.size() - 1);
  }
};
