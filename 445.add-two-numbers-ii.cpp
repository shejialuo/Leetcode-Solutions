/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] Add Two Numbers II
 */

#include <stack>
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
  void addNodeToStack(ListNode *l, stack<ListNode *> &st) {
    while (l != nullptr) {
      st.push(l);
      l = l->next;
    }
  }

public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    stack<ListNode *> st1{};
    stack<ListNode *> st2{};

    addNodeToStack(l1, st1);
    addNodeToStack(l2, st2);

    ListNode *ptr = nullptr;

    int C = 0;
    while (!st1.empty() || !st2.empty()) {
      int val1 = 0;
      if (!st1.empty()) {
        val1 = st1.top()->val;
        st1.pop();
      }
      int val2 = 0;
      if (!st2.empty()) {
        val2 = st2.top()->val;
        st2.pop();
      }

      int sum = (val1 + val2 + C) % 10;
      C = (val1 + val2 + C) / 10;

      ListNode *node = new ListNode{sum};
      if (ptr != nullptr) {
        node->next = ptr;
        ptr = node;
      } else {
        ptr = node;
      }
    }

    if (C != 0) {
      ListNode *node = new ListNode{C};
      if (ptr != nullptr) {
        node->next = ptr;
        ptr = node;
      } else {
        ptr = node;
      }
    }

    return ptr;
  }
};
// @lc code=end
