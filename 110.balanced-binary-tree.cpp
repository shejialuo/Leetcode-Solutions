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
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
  bool ans = true;
  int isBalancedHelper(TreeNode* node) {
    if(node != nullptr) {
      int leftDepth = isBalancedHelper(node->left) + 1;
      int rightDepth = isBalancedHelper(node->right) + 1;
      if (abs(leftDepth - rightDepth) > 1) {
        ans = false;
      }
      return max(leftDepth, rightDepth);
    }
    return 0;
  }
public:
  bool isBalanced(TreeNode* root) {
    isBalancedHelper(root);
    return ans;
  }
};
// @lc code=end

