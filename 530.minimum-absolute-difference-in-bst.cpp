/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] Minimum Absolute Difference in BST
 */

#include <cmath>
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

  void getMinimumDifferenceHelper(TreeNode *node, int &previousNumber,
                                  int &difference) {
    if (node != nullptr) {
      getMinimumDifferenceHelper(node->left, previousNumber, difference);
      difference = difference <= abs(node->val - previousNumber)
                       ? difference
                       : abs(node->val - previousNumber);
      previousNumber = node->val;
      getMinimumDifferenceHelper(node->right, previousNumber, difference);
    }
  }

public:
  int getMinimumDifference(TreeNode *root) {
    int difference = numeric_limits<int>::max();
    int previousNumber = numeric_limits<int>::max();
    getMinimumDifferenceHelper(root, previousNumber, difference);
    return difference;
  }
};
// @lc code=end
