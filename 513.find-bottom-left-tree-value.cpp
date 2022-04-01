/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
  int maxDepth {0};
  int ans {0};
public:

  void dfs(TreeNode* node, int depth) {
    if(node != nullptr) {
      if(depth > maxDepth) {
        ans = node->val;
        maxDepth = depth;
      }
      dfs(node->left, depth + 1);
      dfs(node->right, depth + 1);
    }
  }

  int findBottomLeftValue(TreeNode* root) {
    maxDepth = -1;
    ans = 0;
    dfs(root, 0);
    return ans;
  }
};
// @lc code=end

