/*
 * @lc app=leetcode.cn id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
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
  int getDecimalValue(ListNode *head) {
    ListNode *cur = head;
    int ans = 0;
    while (cur != nullptr) {
      ans = ans * 2 + cur->val;
      cur = cur->next;
    }
    return ans;
  }
};
// @lc code=end
