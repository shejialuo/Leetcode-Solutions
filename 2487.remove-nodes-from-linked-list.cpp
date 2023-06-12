/*
 * @lc app=leetcode.cn id=2487 lang=cpp
 *
 * [2487] Remove Nodes From Linked List
 */

#include <limits>
#include <memory>
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
public:
  /**
   * @brief Use monolithic stack to solve this problem.
   *
   */
  ListNode *removeNodes(ListNode *head) {
    auto aux = make_unique<ListNode>(numeric_limits<int>::max(), head);

    stack<ListNode *> st{};
    st.push(aux.get());

    ListNode *ptr = aux->next;
    for (ListNode *ptr = aux->next; ptr != nullptr; ptr = ptr->next) {
      while (!st.empty() && st.top()->val < ptr->val) {
        st.pop();
      }

      st.top()->next = ptr;
      st.push(ptr);
      ptr = ptr->next;
    }

    return aux->next;
  }
};
// @lc code=end
