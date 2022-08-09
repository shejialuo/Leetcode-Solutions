/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] Reverse Linked List II
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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if(left == right) return head;
    ListNode* aux = new ListNode(0, head);
    ListNode* prevLeftNode = aux;
    for(int i = 0; i < left - 1; ++i) {
      prevLeftNode = prevLeftNode->next;
    }
    ListNode* prev = prevLeftNode->next;
    ListNode* p = prev->next;
    for(int i = 0; i < right - left; ++i) {
      ListNode* temp = p->next;
      p->next = prev;
      prev = p;
      p = temp;
    }
    ListNode* temp = prevLeftNode->next;
    prevLeftNode->next = prev;
    temp->next = p;
    ListNode* ans = aux->next;
    delete aux;
    return ans;
  }
};
// @lc code=end

