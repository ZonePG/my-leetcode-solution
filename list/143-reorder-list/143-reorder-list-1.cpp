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
  void reorderList(ListNode *head) {
    vector<ListNode*> res;

    ListNode *node = head;
    while (node) {
      res.push_back(node);
      node = node->next;
    }

    int i = 0;
    int j = res.size() - 1;
    while (i < j) {
      res[i]->next = res[j];
      i++;
      res[j]->next = res[i];
      j--;
    }
    res[i]->next = nullptr;
  }
};
