/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // There is only one element
    if(head->next == nullptr) {
      return nullptr;
    }
    int i = 0;
    ListNode* p1 = head;
    ListNode* p2 = head;
    while(i <= n && p2 != nullptr) {
      p2 = p2 -> next;
      i++;
    }
    // When deleting the first element
    if(i == n) {
      ListNode* ans = head->next;
      head->next = nullptr;
      return ans;
    }
    // When deleting the second element
    if(i == n - 1) {
      head->next = head->next->next;
      return head;
    }
    while(p2 != nullptr) {
      p1 = p1 ->next;
      p2 = p2-> next;
    }
    p1->next = p1->next->next;
    return head;
  }
};
// @lc code=end

