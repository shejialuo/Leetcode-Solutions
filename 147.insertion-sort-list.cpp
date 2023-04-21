/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] Insertion Sort List
 */

#include <limits>
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
    ListNode *aux = new ListNode{numeric_limits<int>::min()};

    ListNode *ptr = head;
    while (ptr != nullptr) {
      ListNode *next = ptr->next;
      ListNode *p = aux, *pre = nullptr;
      for (; p != nullptr; p = p->next) {
        if (p->val > ptr->val) {
          break;
        }
        pre = p;
      }
      pre->next = ptr;
      ptr->next = p;

      ptr = next;
    }
    ListNode *ans = aux->next;
    delete aux;
    return ans;
  }
};
// @lc code=end
