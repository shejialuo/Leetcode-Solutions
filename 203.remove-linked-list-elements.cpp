/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
  ListNode *removeElements(ListNode *head, int val) {
    auto aux = std::make_unique<ListNode>(0, head);
    ListNode *ptr = aux.get();
    while (ptr != nullptr) {
      if (ptr->next != nullptr && ptr->next->val == val) {
        ptr->next = ptr->next->next;
      } else {
        ptr = ptr->next;
      }
    }
    return aux->next;
  }
};
// @lc code=end
