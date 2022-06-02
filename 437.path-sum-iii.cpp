/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] Path Sum III
 */

// TODO: Need to refactor, there are too many overlap.

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
  int pathSumHelper(TreeNode* node, long sum ,int targetSum) {
    if(node != nullptr) {
      sum += node->val;
      int val = 0;
      if(sum == targetSum) {
        val = 1;
      }
      return val
            +pathSumHelper(node->left, sum, targetSum)
            +pathSumHelper(node->right, sum, targetSum);
    }
    return 0;
  }
public:
  int pathSum(TreeNode* root, int targetSum) {
    if(root != nullptr) {
      return pathSumHelper(root, 0, targetSum)
            +pathSum(root->left, targetSum)
            +pathSum(root->right, targetSum);
    }
    return 0;
  }
};
// @lc code=end

