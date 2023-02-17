/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
 */

#include <cmath>
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
private:
  /**
   * @brief Here we should use the idea of the post order traversing.
   *
   */
  int isBalancedHelper(TreeNode *node) {
    if (node != nullptr) {
      int leftDepth = isBalancedHelper(node->left);
      int rightDepth = isBalancedHelper(node->right);

      if (leftDepth == -1 || rightDepth == -1 ||
          abs(leftDepth - rightDepth) > 1) {
        return -1;
      }
      return max(leftDepth, rightDepth) + 1;
    }
    return 0;
  }

public:
  bool isBalanced(TreeNode *root) { return isBalancedHelper(root) >= 0; }
};
// @lc code=end
