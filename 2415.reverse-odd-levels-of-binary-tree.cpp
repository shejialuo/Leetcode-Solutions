/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] Reverse Odd Levels of Binary Tree
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

#include <algorithm>
using namespace std;

class Solution {
private:
  void reverseOddLevelsHelper(int depth, TreeNode *node1, TreeNode *node2) {
    if (node1 != nullptr) {
      if (depth % 2 != 0) {
        swap(node1->val, node2->val);
      }
      reverseOddLevelsHelper(depth + 1, node1->left, node2->right);
      reverseOddLevelsHelper(depth + 1, node1->right, node2->left);
    }
  }

public:
  TreeNode *reverseOddLevels(TreeNode *root) {
    if (root == nullptr || root->left == nullptr) {
      return root;
    }
    reverseOddLevelsHelper(1, root->left, root->right);
    return root;
  }
};
// @lc code=end
