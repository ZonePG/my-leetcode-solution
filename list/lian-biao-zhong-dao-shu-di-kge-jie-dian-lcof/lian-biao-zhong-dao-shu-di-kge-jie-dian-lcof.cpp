/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *getKthFromEnd(ListNode *head, int k) {
    ListNode *low = head;
    ListNode *fast = head;
    for (int i = 0; i < k; i++) {
      if (fast == nullptr) {
        return nullptr;
      }
      fast = fast->next;
    }
    while (fast) {
      fast = fast->next;
      low = low->next;
    }
    return low;
  }
};
