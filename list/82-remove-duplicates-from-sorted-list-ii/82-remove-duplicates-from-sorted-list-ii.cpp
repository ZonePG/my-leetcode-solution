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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode *pre = dummyNode;
    ListNode *low = head;

    while (low) {

      ListNode *fast = low->next;
      int lowValue = low->val;
      if (fast && lowValue == fast->val) {
        pre->next = fast;
        delete low;
      } else {
        pre = low;
      }

      while (fast && lowValue == fast->val) {
        ListNode *fastNext = fast->next;
        pre->next = fastNext;
        delete fast;
        fast = fastNext;
      }

      low = fast;
    }

    return dummyNode->next;
  }
};
