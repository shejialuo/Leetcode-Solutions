/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * The most simplest idea is that we just use a sentinel
 * to swap every adjacent nodes. However, that's a little
 * tedious. We should think about this question in a higher
 * level.
 *
 * If we want to swap the adjacent node n1 and n2, the process
 * is easy, just make `n1->next = n2->next` and `n2->next = n1`.
 * But the question is that we should swap every adjacent node,
 * this doesn't work.
 *
 * For example, 1->2->3->4, if we use the idea above, we would
 * get 2->1->3 and 4->3. So the problem is how to make change the
 * relationship 1->3 to 1->4. It may seem that we need to operate
 * on the `node->next`. We should convert the way, instead of
 * changing the relationship, why not change the `ListNode*`'s value?
 *
 * So this problem we use a pointer to pointer to solve this question.
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
  ListNode *swapPairs(ListNode *head) {
    ListNode **p = &head;
    ListNode *adjacentFirst{};
    ListNode *adjacentSecond{};
    while ((adjacentFirst = *p) && (adjacentSecond = (*p)->next)) {
      // Here we do normal LinkNode swap
      adjacentFirst->next = adjacentSecond->next;
      adjacentSecond->next = adjacentFirst;

      // Now we make current pointer to ListNode* to
      // be the value of the `adjacentSecond`.
      *p = adjacentSecond;
      p = &(adjacentFirst->next);
    }
    return head;
  }
};
// @lc code=end
