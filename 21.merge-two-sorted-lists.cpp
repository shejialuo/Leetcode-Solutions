/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* ptr1 = list1;
    ListNode* ptr2 = list2;
    ListNode* ptr = nullptr;
    ListNode* result = nullptr;
    while(ptr1 != nullptr && ptr2 != nullptr) {
      int lessValue = 0;
      if(ptr1->val <= ptr2->val) {
        lessValue = ptr1->val;
        ptr1 = ptr1->next;
      } else {
        lessValue = ptr2->val;
        ptr2 = ptr2->next;
      }
      ListNode* node = new ListNode(lessValue, nullptr);
      if(ptr == nullptr) {
        result = node;
      } else {
        ptr->next = node;
      }
      ptr = node;
    }

    while (ptr1 != nullptr) {
      ListNode* node = new ListNode(ptr1->val, nullptr);
      if(ptr == nullptr) {
        result = node;
      } else {
        ptr->next = node;
      }
      ptr = node;
      ptr1 = ptr1->next;
    }

    while (ptr2 != nullptr) {

      ListNode* node = new ListNode(ptr2->val, nullptr);
      if(ptr == nullptr) {
        result = node;
      } else {
        ptr->next = node;
      }
      ptr = node;
      ptr2 = ptr2->next;
    }

    return result;
  }
};
// @lc code=end

