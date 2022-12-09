/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] Path Sum
 */

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
  bool dfs(TreeNode *node, int sum, const int &targetSum) {
    if (node != nullptr) {
      sum += node->val;
      if (node->left == nullptr && node->right == nullptr) {
        if (sum == targetSum)
          return true;
      }
      return dfs(node->left, sum, targetSum) || dfs(node->right, sum, targetSum);
    }
    return false;
  }

public:
  bool hasPathSum(TreeNode *root, int targetSum) { return dfs(root, 0, targetSum); }
};
// @lc code=end
