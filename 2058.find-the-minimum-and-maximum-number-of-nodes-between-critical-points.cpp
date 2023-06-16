/*
 * @lc app=leetcode.cn id=2058 lang=cpp
 *
 * [2058] Find the Minimum and Maximum Number of Nodes Between Critical Points
 */

#include <algorithm>
#include <limits>
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
  vector<int> nodesBetweenCriticalPoints(ListNode *head) {
    int minDistance = numeric_limits<int>::max(), maxDistance = -1;

    int firstIndex = -1;
    int previousIndex = -1;

    ListNode *pre = nullptr;
    ListNode *ptr = head;

    int index = 0;

    while (ptr != nullptr && ptr->next != nullptr) {
      if (pre != nullptr) {
        if ((pre->val < ptr->val && ptr->val > ptr->next->val) ||
            (pre->val > ptr->val && ptr->val < ptr->next->val)) {
          if (firstIndex == -1) {
            firstIndex = index;
          } else {
            maxDistance = max(maxDistance, index - firstIndex);
          }

          if (previousIndex != -1) {
            minDistance = min(minDistance, index - previousIndex);
          }
          previousIndex = index;
        }
      }
      pre = ptr;
      ptr = ptr->next;
      index++;
    }

    if (minDistance == numeric_limits<int>::max()) {
      minDistance = -1;
    }

    return vector<int>{minDistance, maxDistance};
  }
};
// @lc code=end
