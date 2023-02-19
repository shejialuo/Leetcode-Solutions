/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
  /**
   * @brief We should think this question recursively. For a node, we have
   * left subtree and right subtree. We should first store the right subtree.
   * and set `node->left == nullptr` and `node->right = node->left`. And what
   * should we do, we need to find the right most pointer to point to the
   * `node->left` and recursively solve this problem.
   *
   */
  void flattenHelper(TreeNode *node) {
    if (node != nullptr) {
      TreeNode *rightNode = node->right;
      node->right = node->left;
      node->left = nullptr;

      TreeNode *ptr = node;
      while (ptr->right != nullptr) {
        ptr = ptr->right;
      }

      ptr->right = rightNode;

      flattenHelper(node->right);
    }
  }

public:
  void flatten(TreeNode *root) { flattenHelper(root); }
};
// @lc code=end
