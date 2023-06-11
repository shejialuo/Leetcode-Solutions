/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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

/*
 * We should maintain the two pointer: slow and fast. However,
 * in this problem, we may delete the head node, so when we
 * need to operate on the head node, we should define an
 * auxiliary node to make the code easier to understand and
 * clean
 */

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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    auto aux = make_unique<ListNode>(0, head);
    ListNode *slow = aux.get();
    ListNode *fast = aux.get();
    for (int i = 0; i < n; i++) {
      fast = fast->next;
    }
    while (fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }
    slow->next = slow->next->next;
    return aux->next;
  }
};
// @lc code=end
