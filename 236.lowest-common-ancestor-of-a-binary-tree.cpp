/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == q || root == p || root == nullptr) {
      return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    // Case 1, we are Ancestor, we return ourselves, we could be the
    // left or right of the children
    if (left != nullptr && right != nullptr) {
      return root;
    }
    // To convey the answer.
    if (left != nullptr) {
      return left;
    }
    // To convey the answer.
    return right;
  }
};
// @lc code=end
