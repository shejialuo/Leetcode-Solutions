/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] Partition List
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
  ListNode *partition(ListNode *head, int x) {
    ListNode *lessHead = new ListNode{-1};
    ListNode *ptrLess = lessHead;

    ListNode *greaterHead = new ListNode{-1};
    ListNode *ptrGreater = greaterHead;

    ListNode *ptr = head;
    while (ptr != nullptr) {
      if (ptr->val < x) {
        ptrLess->next = ptr;
        ptrLess = ptr;
      } else {
        ptrGreater->next = ptr;
        ptrGreater = ptr;
      }
      ptr = ptr->next;
    }

    ptrLess->next = greaterHead->next;
    ptrGreater->next = nullptr;

    ListNode *ans = lessHead->next;
    delete lessHead;
    delete greaterHead;

    return ans;
  }
};
// @lc code=end
