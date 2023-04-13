/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 */

#include <limits>
#include <queue>
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
public:
  int maxLevelSum(TreeNode *root) {
    queue<TreeNode *> qu{};
    if (root != nullptr) {
      qu.push(root);
    }

    int level = 1;
    int ans = 1;
    int maxSum = numeric_limits<int>::min();

    while (!qu.empty()) {
      int size = qu.size();
      int sum = 0;
      for (int i = 0; i < size; ++i) {
        TreeNode *node = qu.front();
        qu.pop();
        sum += node->val;
        if (node->left != nullptr) {
          qu.push(node->left);
        }
        if (node->right != nullptr) {
          qu.push(node->right);
        }
      }
      if (sum > maxSum) {
        maxSum = sum;
        ans = level;
      }
      level++;
    }
    return ans;
  }
};
// @lc code=end
