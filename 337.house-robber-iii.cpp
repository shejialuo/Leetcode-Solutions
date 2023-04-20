/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] House Robber III
 */

#include <cstddef>
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#include <algorithm>
#include <utility>
using namespace std;

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
  // Bad idea
  int robBruteForce(TreeNode *node, bool allowed) {
    if (node != nullptr) {
      if (allowed) {
        return max(node->val + robBruteForce(node->left, false) +
                       robBruteForce(node->right, false),
                   robBruteForce(node->left, true) +
                       robBruteForce(node->right, true));
      } else {
        return robBruteForce(node->left, true) +
               robBruteForce(node->right, true);
      }
    }
    return 0;
  }

  pair<int, int> robTreeDP(TreeNode *node) {
    if (node != nullptr) {

      auto [leftWithoutThievery, leftWithThievery] = robTreeDP(node->left);
      auto [rightWithoutThievery, rightWithThievery] = robTreeDP(node->right);

      int nodeWithThievery =
          node->val + leftWithoutThievery + rightWithoutThievery;

      int nodeWithoutThievery = max(leftWithoutThievery, leftWithThievery) +
                                max(rightWithoutThievery, rightWithThievery);

      return {nodeWithoutThievery, nodeWithThievery};
    }
    return {0, 0};
  }

public:
  int rob(TreeNode *root) {
    // Brute Force
    // return max(robBruteForce(root, true), robBruteForce(root, false));
    auto [val1, val2] = robTreeDP(root);
    return max(val1, val2);
  }
};
// @lc code=end
