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
      ListNode *plow = head;
      ListNode *pfast = head->next;
      while (plow && pfast) {
        if (plow == pfast)
          return true;
        plow = plow->next;
        if (pfast->next)
          pfast = pfast->next->next;
        else
          return false;
      }
      return false;
    }
};
