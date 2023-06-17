/*
 * @lc app=leetcode.cn id=2074 lang=cpp
 *
 * [2074] Reverse Nodes in Even Length Groups
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
private:
  ListNode *reverseHelper(ListNode *start, ListNode *end) {
    ListNode *pre = start->next;
    ListNode *ptr = pre->next;

    while (ptr != end) {
      ListNode *nextPtr = ptr->next;
      ptr->next = pre;
      pre = ptr;
      ptr = nextPtr;
    }

    ListNode *startNext = start->next;
    start->next = pre;
    startNext->next = end;
    return startNext;
  }

public:
  ListNode *reverseEvenLengthGroups(ListNode *head) {

    auto aux = make_unique<ListNode>(-1, head);

    int groupLength = 1;

    ListNode *ptr = aux.get();

    while (ptr->next != nullptr) {
      ListNode *start = ptr;
      ListNode *end = ptr;

      int currentLength = 0;
      while (currentLength < groupLength && end->next != nullptr) {
        currentLength++;
        end = end->next;
      }

      if (currentLength % 2 == 0) {
        ptr = reverseHelper(start, end->next);
      } else {
        ptr = end;
      }

      groupLength++;
    }

    return aux->next;
  }
};
// @lc code=end
