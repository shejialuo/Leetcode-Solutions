/*
 * @lc app=leetcode.cn id=938 lang=cpp
 *
 * [938] Range Sum of BST
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
  void rangeSumBSTHelper(TreeNode *node, int &ans, int low, int high) {
    if (node != nullptr) {
      if (node->val > high) {
        rangeSumBSTHelper(node->left, ans, low, high);
      } else if (node->val < low) {
        rangeSumBSTHelper(node->right, ans, low, high);
      } else {
        ans += node->val;
        rangeSumBSTHelper(node->left, ans, low, high);
        rangeSumBSTHelper(node->right, ans, low, high);
      }
    }
  }

public:
  int rangeSumBST(TreeNode *root, int low, int high) {
    int ans = 0;
    rangeSumBSTHelper(root, ans, low, high);
    return ans;
  }
};
// @lc code=end
