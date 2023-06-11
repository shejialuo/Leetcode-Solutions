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
   * to the start->3->2->1->end. And returns the 1 for the next
   * iteration. It'easy we convert 1->2->3 to 3->2->1. Then the node
   * will be 3->2->1 , start->1, end. So we would let start->3,
   * 1->end.
   *
   */
  ListNode *reverseKGroupHelper(ListNode *start, ListNode *end) {

    ListNode *pre = start->next;
    ListNode *next = pre->next;

    while (next != end) {
      ListNode *temp = next->next;
      next->next = pre;
      pre = next;
      next = temp;
    }

    ListNode *first = start->next;
    start->next = pre;
    first->next = end;

    return first;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    ListNode *aux = new ListNode(-1, head);

    ListNode *ptr = aux;
    while (aux != nullptr) {
      ListNode *start = ptr, *end = ptr;
      int i = 0;
      for (; i < k + 1 && end != nullptr; ++i) {
        end = end->next;
      }
      if (end == nullptr && i != k + 1) {
        break;
      }
      ptr = reverseKGroupHelper(start, end);
    }

    ListNode *ans = aux->next;
    delete aux;
    return ans;
  }
};
// @lc code=end
