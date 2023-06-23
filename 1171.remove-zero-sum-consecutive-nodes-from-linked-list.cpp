/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 *
 * [1171] Remove Zero Sum Consecutive Nodes from Linked List
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
  ListNode *removeZeroSumSublists(ListNode *head) {
    auto aux = make_unique<ListNode>(-1, head);

    ListNode *ptr = aux.get();
    while (ptr != nullptr && ptr->next != nullptr) {
      ListNode *start = ptr->next;
      int sum = 0;
      while (start != nullptr) {
        sum += start->val;
        start = start->next;
        if (sum == 0) {
          break;
        }
      }
      if (sum == 0) {
        ptr->next = start;
      } else {
        ptr = ptr->next;
      }
    }

    return aux->next;
  }
};
// @lc code=end
