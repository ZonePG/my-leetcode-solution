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
public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *p1 = l1;
    ListNode *p2 = l2;
    ListNode *pre1 = new ListNode(0);
    ListNode *pre2 = new ListNode(0);
    pre1->next = p1;
    pre2->next = p2;

    while (p1 && p2) {
      if (p1->val < p2->val) {
        cout << p1->val << endl;
        p1 = p1->next;
        pre1 = pre1->next;
      } else if (p1->val > p2->val) {
        cout << p2->val << endl;
        p2 = p2->next;
        pre2 = pre2->next;
      } else {
        pre1->next = p1->next;
        pre2->next = p2->next;
        delete p1;
        delete p2;
        p1 = pre1->next;
        p2 = pre2->next;
      }
    }
    while (p1) {
      cout << p1->val << endl;
      p1 = p1->next;
    }
    while (p2) {
      cout << p2->val << endl;
      p2 = p2->next;
    }
    return nullptr;
  }
};
