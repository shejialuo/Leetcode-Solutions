/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] Sort List
 */

#include <memory>
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
    auto aux = make_unique<ListNode>(-1);
    ListNode *ptr = aux.get();
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

    return make_pair(aux->next, ptr);
  }

public:
  /**
   * @brief For this problem, the most easy implementation would be divide and
   * conquer way. We could divide the two list into two, two ,and two. At last
   * we could merge it as two sorted listed. (Merge sort)
   *
   * However, the up-to-bottom would cost memory. We could think it bottom to
   * up. Well, we could set up the subLength to 1. And to be 2. We would
   * get two list with the same length, thus we could achieve this.
   *
   */
  ListNode *sortList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }

    auto aux = make_unique<ListNode>(-1, head);

    int length = 0;
    for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
      length++;
    }

    for (int subLength = 1; subLength < length; subLength *= 2) {
      ListNode *end = aux.get();
      ListNode *ptr = end->next;

      while (ptr != nullptr) {
        ListNode *pre = nullptr;
        ListNode *l1 = ptr;

        for (int i = 0; i < subLength && ptr != nullptr; i++) {
          pre = ptr;
          ptr = ptr->next;
        }

        pre->next = nullptr;

        ListNode *l2 = ptr;

        for (int i = 0; i < subLength && ptr != nullptr; i++) {
          pre = ptr;
          ptr = ptr->next;
        }

        pre->next = nullptr;

        auto &&[s, e] = mergeTwoSortedList(l1, l2);
        end->next = s;
        end = e;
      }
    }
    return aux->next;
  }
};
// @lc code=end
