/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] Insert into a Binary Search Tree
 */

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
public:
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    TreeNode *ptr = root;
    TreeNode *parent = nullptr;
    while (ptr != nullptr) {
      parent = ptr;
      if (ptr->val > val) {
        ptr = ptr->left;
      } else {
        ptr = ptr->right;
      }
    }

    TreeNode *node = new TreeNode{val};
    if (parent == nullptr) {
      root = node;
    } else {
      if (parent->val > val) {
        parent->left = node;
      } else {
        parent->right = node;
      }
    }

    return root;
  }
};
// @lc code=end
