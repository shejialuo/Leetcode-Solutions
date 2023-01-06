/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
  ListNode *deleteDuplicates(ListNode *head) {
    ListNode *ans = head;
    if (head == nullptr) {
      return ans;
    }

    while (head && head->next) {
      if (head->val == head->next->val) {
        head->next = head->next->next;
      } else {
        head = head->next;
      }
    }

    return ans;
  }
};
// @lc code=end
