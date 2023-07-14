/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/*
 * For this question, we may think to use hash table
 * to store the pointer and use time O(m + n) and
 * space O(m) or O(n).
 *
 * However, no matter what, we assume that there is an
 * intersection. For A, the distance between the head
 * and the intersection is m. For B, the distance between
 * the head and the intersection is n. And the common part
 * is l.
 *
 * We should make the ptr1 traverse A and then traverse
 * B and ptr2 traverse B and A. We assume m > n. when
 * ptr1 hits the A's end. The ptr2 is at the A's (m - n)
 * position and the ptr1 is at the B's head. And the distance
 * between the intersection is m - (m - n) = n and n - 0 = n.
 *
 * Thus, if there is an intersection, we must find the node,
 * otherwise, we get the nullptr. Nice idea.
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    while (p1 != p2) {
      if (p1 == nullptr) {
        p1 = headB;
      } else {
        p1 = p1->next;
      }
      if (p2 == nullptr) {
        p2 = headA;
      } else {
        p2 = p2->next;
      }
    }
    return p1;
  }
};
// @lc code=end
