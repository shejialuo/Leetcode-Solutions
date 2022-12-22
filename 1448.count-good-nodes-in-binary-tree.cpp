/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] Count Good Nodes in Binary Tree
 */

#include <limits>
using namespace std;

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
   * @brief Simple idea, to maintain the max value
    in the path
   *
   */
  void goodNodesHelper(TreeNode *node, int maxValue, int &ans) {
    if (node != nullptr) {
      if (node->val >= maxValue) {
        maxValue = node->val;
        ans++;
      }
      goodNodesHelper(node->left, maxValue, ans);
      goodNodesHelper(node->right, maxValue, ans);
    }
  }

public:
  int goodNodes(TreeNode *root) {
    int ans = 0;
    goodNodesHelper(root, numeric_limits<int>::min(), ans);
    return ans;
  }
};
// @lc code=end
