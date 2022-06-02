/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
  int sumOfLeftLeavesHelper(TreeNode* node, bool isLeft) {
    if(node != nullptr) {
      int num = 0;
      if(node->left == nullptr && node->right == nullptr && isLeft) {
        num = node->val;
      }
      return num
            +sumOfLeftLeavesHelper(node->left, true)
            +sumOfLeftLeavesHelper(node->right, false);
    }
    return 0;
  }
public:
  int sumOfLeftLeaves(TreeNode* root) {
    return sumOfLeftLeavesHelper(root, false);
  }
};
// @lc code=end

