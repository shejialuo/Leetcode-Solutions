/*
 * @lc app=leetcode.cn id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
  ListNode *deleteMiddle(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *slow = head, *fast = head;
    while (fast != nullptr) {
      fast = fast->next;
      if (fast != nullptr) {
        fast = fast->next;
        pre = slow;
        slow = slow->next;
      }
    }

    if (pre == nullptr) {
      return pre;
    }
    pre->next = slow->next;
    return head;
  }
};
// @lc code=end
