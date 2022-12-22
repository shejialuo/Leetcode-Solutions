/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 *
 * [1721] Swapping Nodes in a Linked List
 */

#include <iostream>
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
  ListNode *swapNodes(ListNode *head, int k) {
    ListNode *headK = head;
    ListNode *rearK = head;
    for (int i = 1; i < k; ++i) {
      headK = headK->next;
    }
    ListNode *ptr = headK;
    while (ptr->next != nullptr) {
      ptr = ptr->next;
      rearK = rearK->next;
    }
    swap(rearK->val, headK->val);
    return head;
  }
};
// @lc code=end
