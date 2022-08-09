/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
  int sumNumbersHelper(TreeNode* node, int sum) {
    if(node != nullptr) {
      sum = node->val + sum * 10;
      if(node->left == nullptr && node->right == nullptr) {
        return sum;
      }
      return sumNumbersHelper(node->left, sum)
            +sumNumbersHelper(node->right, sum);
    }
    return 0;
  }
public:
  int sumNumbers(TreeNode* root) {
    return sumNumbersHelper(root, 0);
  }
};
// @lc code=end

