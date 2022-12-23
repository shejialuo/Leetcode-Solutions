/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
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
  void deepestLeavesSumHelper(TreeNode *node, int &maxDepth, int depth,
                              int &ans) {
    if (node != nullptr) {
      if (depth > maxDepth) {
        ans = node->val;
        maxDepth = depth;
      } else if (depth == maxDepth) {
        ans += node->val;
      }
      deepestLeavesSumHelper(node->left, maxDepth, depth + 1, ans);
      deepestLeavesSumHelper(node->right, maxDepth, depth + 1, ans);
    }
  }

public:
  int deepestLeavesSum(TreeNode *root) {
    int ans = 0;
    int maxDepth = 0;
    deepestLeavesSumHelper(root, maxDepth, 0, ans);
    return ans;
  }
};
// @lc code=end
