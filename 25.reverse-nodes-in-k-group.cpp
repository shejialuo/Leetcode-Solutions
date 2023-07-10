/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

#include <memory>
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
    ListNode *nextStart = start->next;

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

    return nextStart;
  }

public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    auto aux = make_unique<ListNode>(-1, head);
    ListNode *ptr = aux.get();

    while (ptr != nullptr) {
      int length = 0;
      ListNode *end = ptr;
      for (; length < k + 1 && end != nullptr; length++) {
        end = end->next;
      }

      if (end == nullptr && length < k + 1) {
        break;
      }

      ptr = reverseKGroupHelper(ptr, end);
    }
    return aux->next;
  }
};
// @lc code=end
