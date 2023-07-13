/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
  bool isSymmetricHelper(TreeNode *node1, TreeNode *node2) {
    if (node1 == nullptr && node2 == nullptr) {
      return true;
    }
    if (node1 != nullptr && node2 != nullptr) {
      if (node1->val == node2->val) {
        return isSymmetricHelper(node1->left, node2->right) &&
               isSymmetricHelper(node1->right, node2->left);
      }
    }
    return false;
  }

public:
  bool isSymmetric(TreeNode *root) {
    if (root == nullptr) {
      return false;
    }
    return isSymmetricHelper(root->left, root->right);
  }
};
// @lc code=end
