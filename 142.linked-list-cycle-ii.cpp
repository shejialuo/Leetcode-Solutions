/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
  ListNode *detectCycle(ListNode *head) {
    ListNode *slowPointer = head;
    ListNode *fastPointer = head;
    if (slowPointer == nullptr) {
      return head;
    }

    while (fastPointer) {
      fastPointer = fastPointer->next;
      if (fastPointer != nullptr) {
        slowPointer = slowPointer->next;
        fastPointer = fastPointer->next;
      }

      if (fastPointer == slowPointer) {
        slowPointer = head;
        while (fastPointer != slowPointer) {
          slowPointer = slowPointer->next;
          fastPointer = fastPointer->next;
        }
        return slowPointer;
      }
    }
    return nullptr;
  }
};
// @lc code=end
