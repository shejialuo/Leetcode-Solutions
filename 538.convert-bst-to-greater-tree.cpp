/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] Convert BST to Greater Tree
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
public:
  void dfs(TreeNode *node, int &sum) {
    if (node != nullptr) {
      dfs(node->right, sum);
      node->val += sum;
      sum = node->val;
      dfs(node->left, sum);
    }
  }

  TreeNode *convertBST(TreeNode *root) {
    TreeNode *ans = root;
    int sum = 0;
    dfs(root, sum);
    return ans;
  }
};
// @lc code=end
