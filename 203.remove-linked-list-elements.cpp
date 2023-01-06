/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
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
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *aux = new ListNode(0, head);
    ListNode *ptr = aux;
    while (ptr && ptr->next) {
      if (ptr->next->val == val) {
        ptr->next = ptr->next->next;
      } else {
        ptr = ptr->next;
      }
    }
    ListNode *result = aux->next;
    delete aux;
    return result;
  }
};
// @lc code=end
