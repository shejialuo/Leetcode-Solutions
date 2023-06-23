/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] Linked List Components
 */

#include <unordered_set>
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
class Solution {
public:
  int numComponents(ListNode *head, vector<int> &nums) {
    unordered_set<int> table{nums.cbegin(), nums.cend()};
    int ans = 0;
    ListNode *ptr = head;
    while (ptr != nullptr) {
      if (table.count(ptr->val)) {
        ptr = ptr->next;
        while (ptr != nullptr && table.count(ptr->val)) {
          ptr = ptr->next;
        }
        ans++;
      } else {
        ptr = ptr->next;
      }
    }
    return ans;
  }
};
// @lc code=end
