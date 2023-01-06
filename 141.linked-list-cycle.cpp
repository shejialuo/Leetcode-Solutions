/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  // Floyd circle detection
  bool hasCycle(ListNode *head) {
    ListNode *slowPointer = head;
    ListNode *fastPointer = head;
    if (slowPointer == nullptr) {
      return false;
    }
    while (fastPointer) {
      fastPointer = fastPointer->next;
      if (fastPointer != nullptr) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;
      }
      if (slowPointer == fastPointer) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
