/*
 * @lc app=leetcode.cn id=1367 lang=cpp
 *
 * [1367] Linked List in Binary Tree
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
  bool isSubPathHelper(ListNode *ptr, TreeNode *node) {
    if (ptr == nullptr) {
      return true;
    }
    if (node == nullptr) {
      return false;
    }

    if (ptr->val != node->val) {
      return false;
    }

    return isSubPathHelper(ptr->next, node->left) ||
           isSubPathHelper(ptr->next, node->right);
  }

public:
  bool isSubPath(ListNode *head, TreeNode *root) {
    if (root == nullptr) {
      return false;
    }
    return isSubPathHelper(head, root) || isSubPath(head, root->left) ||
           isSubPath(head, root->right);
  }
};
// @lc code=end
