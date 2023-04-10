/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] Next Greater Node In Linked List
 */

#include <stack>
#include <utility>
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
  vector<int> nextLargerNodes(ListNode *head) {
    vector<int> ans{};
    stack<pair<int, int>> st{};

    ListNode *ptr = head;

    int index = 0;
    while (ptr != nullptr) {
      while (!st.empty() && st.top().first < ptr->val) {
        ans[st.top().second] = ptr->val;
        st.pop();
      }
      st.push(make_pair(ptr->val, index));
      ptr = ptr->next;
      index++;
      ans.push_back(0);
    }

    return ans;
  }
};
// @lc code=end
