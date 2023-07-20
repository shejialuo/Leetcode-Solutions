/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
 */

#include <algorithm>
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
   * @brief We should carefully think about this question. For a node,
   * its value could be only itself, itself + leftSubTree, itself + rightSubTree
   * and itself + leftSubTree + rightSubTree.
   * However, when the node forms a path, we should only have one option,
   * combine it either with leftSubTree and rightSubTree.
   *
   */
  int maxPathSumHelper(TreeNode *node, int &maxSum) {
    if (node != nullptr) {
      int left = maxPathSumHelper(node->left, maxSum);
      int right = maxPathSumHelper(node->right, maxSum);

      int maxPathValue = max({left + node->val, right + node->val, node->val});
      maxSum = max({maxSum, left + right + node->val, maxPathValue});

      return maxPathValue;
    }
    return 0;
  }

public:
  int maxPathSum(TreeNode *root) {
    int maxSum = numeric_limits<int>::min();
    maxPathSumHelper(root, maxSum);
    return maxSum;
  }
};
// @lc code=end
