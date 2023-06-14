/*
 * @lc app=leetcode.cn id=1669 lang=cpp
 *
 * [1669] Merge In Between Linked Lists
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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *end = list2;
    while (end->next != nullptr) {
      end = end->next;
    }

    ListNode *aThBefore = list1;
    ListNode *bThAfter = list1;
    for (int i = 0; i < a - 1; i++) {
      aThBefore = aThBefore->next;
      bThAfter = bThAfter->next;
    }

    for (int i = 0; i < b - a + 2; i++) {
      bThAfter = bThAfter->next;
    }

    aThBefore->next = list2;
    end->next = bThAfter;

    return list1;
  }
};
// @lc code=end
