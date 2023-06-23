/*
 * @lc app=leetcode.cn id=2181 lang=cpp
 *
 * [2181] Merge Nodes in Between Zeros
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
  ListNode *mergeNodes(ListNode *head) {

    auto aux = make_unique<ListNode>(-1, head);

    ListNode *ptr = aux.get();

    while (ptr != nullptr && ptr->next != nullptr) {
      if (ptr->next->val == 0) {
        int sum = 0;
        ListNode *p = ptr->next->next;
        while (p != nullptr && p->val != 0) {
          sum += p->val;
          p = p->next;
        }
        if (p != nullptr) {
          ptr->next->val = sum;
          ptr->next->next = p;
        } else {
          ptr->next = nullptr;
        }
      } else {
        ptr = ptr->next;
      }
    }

    return aux->next;
  }
};
// @lc code=end
