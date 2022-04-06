/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] Rotate List
 */

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
  ListNode* rotateRight(ListNode* head, int k) {
    if(head == nullptr) {
      return head;
    }
    ListNode* p1 = head;
    ListNode* p2;
    int length = 0;
    while(p1 != nullptr) {
      length++;
      p2 = p1;
      p1 = p1 -> next;
    }
    p2->next = head;
    p1 = head;
    int offset = length - (k % length);
    if(offset == 0) return head;
    for(int i = 0; i < offset - 1; ++i) {
      p1 = p1 ->next;
    }
    ListNode* result = p1 -> next;
    p1 -> next = nullptr;
    return result;
  }
};
// @lc code=end

