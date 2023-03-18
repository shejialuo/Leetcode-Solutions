/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

#include <utility>
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
private:
  /**
   * @brief For example, start->1->2->3->end, we should convert it
   * to the start->3->2-1->end. And returns the 1. And we could
   * solve it easily.
   *
   */
  ListNode *reverseKGroupHelper(ListNode *start, ListNode *end) {

    ListNode *current = start->next;
    ListNode *ptr = current;
    ListNode *next = current->next;

    while (next != end) {
      ListNode *temp = next->next;
      next->next = current;
      current = next;
      next = temp;
    }

    start->next = current;
    ptr->next = end;

    return ptr;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *aux = new ListNode(-1, head);
    ListNode *start = aux;
    ListNode *end = start->next;
    while (end != nullptr) {
      int i = 0;
      for (; i < k && end != nullptr; ++i) {
        end = end->next;
      }
      if (end == nullptr && i != k) {
        break;
      }
      start = reverseKGroupHelper(start, end);
      end = start->next;
    }
    return aux->next;
  }
};
// @lc code=end
