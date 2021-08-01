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
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    ListNode *low = head;
    ListNode *fast = head;
    while (fast) {
      low = low->next;
      if (fast->next == nullptr) {
        return nullptr;
      }
      fast = fast->next->next;
      if (fast == low) {
        ListNode *ptr = head;
        while (ptr != low) {
          ptr = ptr->next;
          low = low->next;
        }
        return ptr;
      }
    }
    return nullptr;
  }
};
