/*
 * @lc app=leetcode.cn id=1325 lang=cpp
 *
 * [1325] Delete Leaves With a Given Value
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
  void removeLeafNodesHelper(TreeNode *node, TreeNode *parent, int target) {
    if (node != nullptr) {
      removeLeafNodesHelper(node->left, node, target);
      removeLeafNodesHelper(node->right, node, target);
      if (node->left == nullptr && node->right == nullptr) {
        if (node->val == target) {
          if (parent->left == node) {
            parent->left = nullptr;
          }
          if (parent->right == node) {
            parent->right = nullptr;
          }
        }
      }
    }
  }

public:
  TreeNode *removeLeafNodes(TreeNode *root, int target) {
    TreeNode *dummy = new TreeNode{-1};
    dummy->left = root;
    removeLeafNodesHelper(root, dummy, target);
    TreeNode *ans = dummy->left;
    delete dummy;
    return ans;
  }
};
// @lc code=end
