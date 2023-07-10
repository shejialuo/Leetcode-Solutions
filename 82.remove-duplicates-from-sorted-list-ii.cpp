/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
  ListNode *deleteDuplicates(ListNode *head) {
    unique_ptr<ListNode> aux = make_unique<ListNode>(-101, head);

    ListNode *ptr = aux.get();

    while (ptr != nullptr) {
      ListNode *next = ptr->next;
      while (next != nullptr && next->next != nullptr &&
             next->next->val == next->val) {
        next = next->next;
      }

      if (ptr->next != next) {
        ptr->next = next->next;
      } else {
        ptr = ptr->next;
      }
    }

    return aux->next;
  }
};
// @lc code=end
