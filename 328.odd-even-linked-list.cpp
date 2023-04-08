/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
  ListNode *oddEvenList(ListNode *head) {
    ListNode *oddStart = nullptr;
    ListNode *evenStart = nullptr;

    ListNode *ptr = head;
    ListNode *ptrForOdd = nullptr;
    ListNode *ptrForEven = nullptr;

    int i = 1;

    while (ptr != nullptr) {
      if (i % 2 != 0) {
        if (oddStart == nullptr) {
          oddStart = ptr;
          ptrForOdd = oddStart;
        } else {
          ptrForOdd->next = ptr;
          ptrForOdd = ptrForOdd->next;
        }

        ListNode *next = ptr->next;
        ptr->next = nullptr;
        ptr = next;
      } else {
        if (evenStart == nullptr) {
          evenStart = ptr;
          ptrForEven = evenStart;
        } else {
          ptrForEven->next = ptr;
          ptrForEven = ptrForEven->next;
        }

        ListNode *next = ptr->next;
        ptr->next = nullptr;
        ptr = next;
      }
      i++;
    }

    if (ptrForOdd != nullptr) {
      ptrForOdd->next = evenStart;
    } else {
      oddStart = evenStart;
    }

    return oddStart;
  }
};
// @lc code=end
