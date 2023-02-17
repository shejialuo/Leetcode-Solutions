/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
 */

#include <iostream>
using namespace std;

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
  /**
   * @brief There is a strick in the code, when the node
   * has only one children, we should not consider the
   * depth is zero.
   *
   */
  int minDepth(TreeNode *root) {
    if (root != nullptr) {
      int L = minDepth(root->left);
      int R = minDepth(root->right);
      return 1 + (L && R ? min(L, R) : max(L, R));
    }
    return 0;
  }
};
// @lc code=end
