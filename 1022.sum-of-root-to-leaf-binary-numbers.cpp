/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
 */

#include <cmath>
#include <string>
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

/*
 * We just use dfs, however, we should use left shift operation
 * to finish the work.
 */

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
  int helper(TreeNode *node, int val) {
    if (node == nullptr)
      return 0;

    val = (val << 1) | node->val;
    if (node->left == nullptr && node->right == nullptr) {
      return val;
    }
    return helper(node->left, val) + helper(node->right, val);
  }

public:
  int sumRootToLeaf(TreeNode *root) { return helper(root, 0); }
};
// @lc code=end
