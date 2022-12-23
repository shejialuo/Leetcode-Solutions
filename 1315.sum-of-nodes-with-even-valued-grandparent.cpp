/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] Sum of Nodes with Even-Valued Grandparent
 */

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
  int sumEvenGrandparentHelper(TreeNode *node, int grandparent, int parent) {
    if (node != nullptr) {
      int val = 0;
      if (grandparent % 2 == 0) {
        val = node->val;
      }
      return val + sumEvenGrandparentHelper(node->left, parent, node->val) +
             sumEvenGrandparentHelper(node->right, parent, node->val);
    }
    return 0;
  }

public:
  int sumEvenGrandparent(TreeNode *root) {
    return sumEvenGrandparentHelper(root, 1, 1);
  }
};
// @lc code=end
