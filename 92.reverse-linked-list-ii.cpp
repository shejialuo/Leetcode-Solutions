/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] Reverse Linked List II
 */

#include <memory>
using namespace std;

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
  /**
   * @brief We need to find the pointer here where
   * leftStart left .. right .. rightEnd
   *
   */
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right) {
      return head;
    }

    auto aux = make_unique<ListNode>(-1, head);
    ListNode *start = aux.get();

    for (int i = 0; i < left - 1; i++) {
      start = start->next;
    }

    ListNode *end = start;
    for (int i = 0; i < right - left + 2; i++) {
      end = end->next;
    }

    ListNode *pre = start->next;
    ListNode *cur = pre->next;
    while (cur != end) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }

    start->next->next = end;
    start->next = pre;

    return aux->next;
  }
};
// @lc code=end
