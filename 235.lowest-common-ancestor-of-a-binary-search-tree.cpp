/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
  // This question is much easier. Because the ancestor must be
  // in the [p, q]. The first node we find in [p, q] is the answer.
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    TreeNode *node = root;
    int low = p->val > q->val ? q->val : p->val;
    int high = p->val > q->val ? p->val : q->val;
    while (node != nullptr) {
      if (node->val <= high && node->val >= low) {
        return node;
      }
      if (node->val > high) {
        node = node->left;
      } else {
        node = node->right;
      }
    }
    return nullptr;
  }
};
// @lc code=end
