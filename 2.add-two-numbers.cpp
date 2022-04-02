/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ans = new ListNode();
    ListNode* rear = ans;
    ListNode* p1 = l1;
    ListNode* p2 = l2;

    int C = 0;

    while(p1 != nullptr || p2 != nullptr) {
      int sum = 0;
      if(p1 == nullptr) {
        sum = (p2->val + C) % 10;
        C = (p2->val + C) / 10;
        p2 = p2->next;
      } else if(p2 == nullptr) {
        sum = (p1->val + C) % 10;
        C = (p1->val + C) / 10;
        p1 = p1->next;
      } else {
        sum = (p1->val + p2->val + C) % 10;
        C = (p1->val + p2->val + C) / 10;
        p1 = p1->next;
        p2 = p2->next;
      }
      ListNode* node = new ListNode(sum);
      rear->next = node;
      rear = node;
    }

    if(C != 0) {
      ListNode* node = new ListNode(C);
      rear->next = node;
    }

    return ans->next;
  }
};
// @lc code=end
