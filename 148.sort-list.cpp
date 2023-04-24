/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] Sort List
 */

#include <utility>
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
  pair<ListNode *, ListNode *> mergeTwoSortedList(ListNode *l1, ListNode *l2) {
    ListNode *aux = new ListNode{-1};
    ListNode *ptr = aux;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        ptr->next = l1;
        l1 = l1->next;
      } else {
        ptr->next = l2;
        l2 = l2->next;
      }
      ptr = ptr->next;
    }

    ptr->next = l1 ? l1 : l2;

    while (ptr->next != nullptr) {
      ptr = ptr->next;
    }

    ListNode *head = aux->next;
    delete aux;
    return make_pair(head, ptr);
  }

public:
  /**
   * @brief For this problem, the most easy implementation would be divide and
   * way. We could divide the two list into two, two ,and two. At last we could
   * merge it as two sorted listed. (Merge sort)
   *
   * However, the up-to-bottom would cost memory. We could think it bottom to
   * up. Well, we could set up the subLength to 1. And to be 2. We would
   * get two list with the same length, thus we could achieve this.
   *
   *
   */
  ListNode *sortList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }

    int length = 0;
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
      length++;
    }

    ListNode *ptr = head;

    // It is hard to write this function correctly, we should also
    // keep the loop invariant.

    // o->o->o->o->o->o->o->o, we assume the subLength is 2.
    // we should break the list to become o->o->nullptr, o->o->nullptr.
    // o->o->o->o->o. When we merge, we get a new o->o->o->o, which
    // will return the head nad the tail. The first head would be the
    // next pointer, the tail would concatenate the next. It's hard
    // do remember maintain the loop invariant.

    for (int subLength = 1; subLength < length; subLength *= 2) {
      ListNode *l1 = nullptr;
      ListNode *l2 = nullptr;

      ListNode *p = ptr;
      ListNode *pre = nullptr;
      ListNode *nextPtr = nullptr;
      ListNode *lastMergedListEnd = nullptr;

      while (p != nullptr) {

        // Get the list1
        l1 = p;
        for (int i = 0; i < subLength && p != nullptr; i++) {
          pre = p;
          p = p->next;
        }

        // break the list1
        pre->next = nullptr;

        // There may be situation that p is nullptr at now,
        // however does not matter at all.
        l2 = p;
        for (int i = 0; i < subLength && p != nullptr; i++) {
          pre = p;
          p = p->next;
        }

        pre->next = nullptr;

        auto [head, tail] = mergeTwoSortedList(l1, l2);
        if (lastMergedListEnd != nullptr) {
          lastMergedListEnd->next = head;
          lastMergedListEnd = tail;
        } else {
          lastMergedListEnd = tail;
        }

        if (nextPtr == nullptr) {
          nextPtr = head;
        }
      }
      ptr = nextPtr;
    }

    return ptr;
  }
};
// @lc code=end
