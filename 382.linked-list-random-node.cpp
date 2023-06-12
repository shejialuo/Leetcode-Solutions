/*
 * @lc app=leetcode.cn id=382 lang=cpp
 *
 * [382] Linked List Random Node
 */

#include <vector>
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

/**
 * @brief This problem uses reservoir sampling.
 *
 */
class Solution {
private:
  ListNode *head;

public:
  Solution(ListNode *head) { this->head = head; }

  int getRandom() {
    int i = 1, ans = 0;
    for (auto node = head; node != nullptr; node = node->next) {
      if (rand() % i == 0) {
        ans = node->val;
      }
      ++i;
    }
    return ans;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
// @lc code=end
