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
    ListNode *leftStart = aux.get();

    for (int i = 0; i < left - 1; i++) {
      leftStart = leftStart->next;
    }

    ListNode *pre = leftStart->next;
    ListNode *next = pre->next;
    for (int i = 0; i < right - left; i++) {
      ListNode *temp = next->next;
      next->next = pre;
      pre = next;
      next = temp;
    }

    ListNode *temp = leftStart->next;
    leftStart->next = pre;
    temp->next = next;

    return aux->next;
  }
};
// @lc code=end
