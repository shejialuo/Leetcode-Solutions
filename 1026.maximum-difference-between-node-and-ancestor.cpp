/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] Maximum Difference Between Node and Ancestor
 */

#include <algorithm>
#include <cmath>
#include <limits>
#include <utility>
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
  pair<int, int> maxAncestorDiffHelper(TreeNode *node, int &maxDiff) {

    if (node != nullptr) {

      auto &&[leftMax, leftMin] = maxAncestorDiffHelper(node->left, maxDiff);
      auto &&[rightMax, rightMin] = maxAncestorDiffHelper(node->right, maxDiff);

      if (node->left != nullptr && node->right != nullptr) {
        maxDiff = max<int>({maxDiff, abs(node->val - leftMax),
                            abs(node->val - leftMin), abs(node->val - rightMax),
                            abs(node->val - rightMin)});
      } else if (node->right != nullptr) {
        maxDiff = max<int>(
            {maxDiff, abs(node->val - rightMax), abs(node->val - rightMin)});
      } else if (node->left != nullptr) {
        maxDiff = max<int>(
            {maxDiff, abs(node->val - leftMax), abs(node->val - leftMin)});
      }

      int maxNum = max<int>({leftMax, rightMax, node->val});
      int minNum = min<int>({leftMin, rightMin, node->val});

      return {maxNum, minNum};
    }
    return {numeric_limits<int>::min(), numeric_limits<int>::max()};
  }

public:
  int maxAncestorDiff(TreeNode *root) {
    int maxDiff = 0;
    maxAncestorDiffHelper(root, maxDiff);
    return maxDiff;
  }
};
// @lc code=end
