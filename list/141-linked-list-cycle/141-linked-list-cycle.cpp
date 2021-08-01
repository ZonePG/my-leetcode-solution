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
    bool hasCycle(ListNode *head) {
      if (head == nullptr)
        return false;
      ListNode *low = head;
      ListNode *fast = head;
      while (fast != nullptr) {
        low = low->next;
        if (fast->next == nullptr) {
          return false;
        }
        fast = fast->next->next;
        if (fast == low)
          return true;
      }
      return false;
    }
};
