/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] Reorder List
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
private:
  ListNode *findMidNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *pre = nullptr;

    while (fast != nullptr) {
      fast = fast->next;
      if (fast != nullptr) {
        fast = fast->next;
      }
      pre = slow;
      slow = slow->next;
    }

    pre->next = nullptr;
    return slow;
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *ptr = head;

    while (ptr != nullptr) {
      ListNode *temp = ptr->next;
      ptr->next = pre;
      pre = ptr;
      ptr = temp;
    }

    return pre;
  }

public:
  void reorderList(ListNode *head) {
    ListNode *mid = findMidNode(head);

    ListNode *ptr1 = head;
    ListNode *ptr2 = reverseList(mid);

    while (ptr1 != nullptr && ptr2 != nullptr) {
      ListNode *next = ptr1->next;
      ptr1->next = ptr2;
      ptr2 = ptr2->next;
      ptr1->next->next = next;
      ptr1 = next;
    }
  }
};
// @lc code=end
