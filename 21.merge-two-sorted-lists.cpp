/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
  * In this problem, we do not need to allocate memory
  * for new node, we just re-organize the node.
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
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* aux = new ListNode(-1);
    ListNode* p = aux;
    while(list1 != nullptr && list2 != nullptr) {
      if(list1->val < list2->val) {
        p->next = list1;
        list1 = list1->next;
      } else {
        p->next = list2;
        list2 = list2->next;
      }
      p = p->next;
    }
    p->next = list1 == nullptr ? list2 : list1;

    ListNode* ans = aux->next;
    delete aux;
    return ans;
  }
};
// @lc code=end

