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
private:
  void reverseList(ListNode *head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
      ListNode* next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
  }
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;

    ListNode *prev = dummyNode;
    // 第 1 步：虚拟头节点走 left - 1步，来到 left 节点的前一个节点
    for (int i = 0; i < left - 1; i++) {
      prev = prev->next;
    }

    // 第 2 步：从 prev 再走 right - left + 1 步，来到 right 节点
    ListNode *rightNode = prev;
    for (int i = 0; i < right - left + 1; i++) {
      rightNode = rightNode->next;
    }

    // 第 3 步：切断出一个子链表（截取链表）
    ListNode *leftNode = prev->next;
    ListNode *curr = rightNode->next;

    // 注意：切断链接
    prev->next = nullptr;
    rightNode->next = nullptr;

    // 第 4 步：反转子链表
    reverseList(leftNode);

    // 第 5 步：接回原来的链表
    prev->next = rightNode;
    leftNode->next = curr;
    return dummyNode->next;
  }
};
