/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] Insertion Sort List
 */

#include <limits>
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
  ListNode *insertionSortList(ListNode *head) {
    auto aux = make_unique<ListNode>(numeric_limits<int>::min());

    ListNode *ptr = head;
    while (ptr != nullptr) {
      ListNode *next = ptr->next;
      ListNode *p = aux.get(), *pre = nullptr;
      for (; p != nullptr; p = p->next) {
        if (p->val > ptr->val) {
          break;
        }
        pre = p;
      }
      pre->next = ptr;
      ptr->next = p;

      ptr = next;
    };
    return aux->next;
  }
};
// @lc code=end
