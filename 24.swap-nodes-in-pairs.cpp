/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

// TODO: need to refactor, use a simpler way.

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
  ListNode* swapPairs(ListNode* head) {
    ListNode* auxNode = new ListNode(-1);
    auxNode->next = head;
    ListNode* ans = auxNode;
    while(auxNode->next != nullptr && auxNode->next->next != nullptr) {
      ListNode* adjacentPrevious = auxNode->next;
      ListNode* adjacentLatter = auxNode->next->next;
      ListNode* temp = adjacentLatter->next;
      adjacentLatter->next = adjacentPrevious;
      auxNode->next = adjacentLatter;
      adjacentPrevious->next = temp;
      auxNode = adjacentPrevious;
    }
    return ans->next;
  }
};
// @lc code=end

