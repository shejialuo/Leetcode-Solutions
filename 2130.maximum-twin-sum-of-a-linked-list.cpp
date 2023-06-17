/*
 * @lc app=leetcode.cn id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 */

#include <algorithm>
#include <limits>

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
  ListNode *findMid(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    ListNode *pre = nullptr;
    while (fast != nullptr) {
      fast = fast->next;
      if (fast != nullptr) {
        fast = fast->next;
        pre = slow;
        slow = slow->next;
      }
    }
    if (pre != nullptr) {
      pre->next = nullptr;
    }
    return slow;
  }

  ListNode *reverse(ListNode *node) {
    ListNode *pre = nullptr;
    ListNode *cur = node;
    while (cur != nullptr) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }

    return pre;
  }

public:
  int pairSum(ListNode *head) {
    int ans = numeric_limits<int>::min();

    ListNode *anotherHead = reverse(findMid(head));

    while (head != nullptr) {
      ans = max(ans, head->val + anotherHead->val);
      head = head->next;
      anotherHead = anotherHead->next;
    }

    return ans;
  }
};
// @lc code=end
