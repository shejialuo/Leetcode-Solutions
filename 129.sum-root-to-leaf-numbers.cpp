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
public:

  void dfs(TreeNode* node, int num, int& ans) {
    if(node != nullptr) {
      num = num * 10 + node->val;
      if(node->left == nullptr && node->right == nullptr) {
        ans += num;
      }
      dfs(node->left, num, ans);
      dfs(node->right, num, ans);
    }
  }

  int sumNumbers(TreeNode* root) {
    int ans = 0;
    dfs(root, 0, ans);
    return ans;
  }
};
// @lc code=end

