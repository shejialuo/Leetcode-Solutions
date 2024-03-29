/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] Partition List
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
  ListNode *partition(ListNode *head, int x) {
    auto less = make_unique<ListNode>();
    auto greater = make_unique<ListNode>();

    ListNode *lessPtr = less.get();
    ListNode *greaterPtr = greater.get();

    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
      if (ptr->val < x) {
        lessPtr->next = ptr;
        lessPtr = ptr;
      } else {
        greaterPtr->next = ptr;
        greaterPtr = ptr;
      }
    }

    lessPtr->next = greater->next;
    greaterPtr->next = nullptr;

    return less->next;
  }
};
// @lc code=end
