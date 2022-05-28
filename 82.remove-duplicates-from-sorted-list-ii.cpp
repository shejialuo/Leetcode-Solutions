/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* aux = new ListNode(0, head);
    ListNode* ptr = aux;
    while(ptr->next != nullptr) {
      ListNode* start = ptr->next;
      bool isSame = false;
      while(start != nullptr && start->next != nullptr) {
          if(start->val == start->next->val) {
              isSame = true;
              start->next = start->next->next;
          } else {
            break;
          }
      }
      if(isSame) {
        ptr->next = start->next;
      } else {
        ptr = ptr->next;
      }
    }
    return aux->next;
  }
};
// @lc code=end

