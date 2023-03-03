/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] Binary Tree Tilt
 */

#include <cstdlib>
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
  int findTiltHelper(TreeNode *node, int &ans) {
    if (node == nullptr) {
      return 0;
    }

    int leftSum = findTiltHelper(node->left, ans);
    int rightSum = findTiltHelper(node->right, ans);

    ans += abs(leftSum - rightSum);

    return node->val + leftSum + rightSum;
  }

public:
  int findTilt(TreeNode *root) {
    int ans = 0;
    findTiltHelper(root, ans);
    return ans;
  }
};
// @lc code=end
