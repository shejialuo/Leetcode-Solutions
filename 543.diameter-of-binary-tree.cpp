/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

#include <algorithm>
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
  int diameterOfBinaryTreeHelper(TreeNode *node, int &ans) {
    if (node != nullptr) {
      int left = diameterOfBinaryTreeHelper(node->left, ans);
      int right = diameterOfBinaryTreeHelper(node->right, ans);

      ans = max(ans, left + right);
      return max(left, right) + 1;
    }
    return 0;
  }

public:
  int diameterOfBinaryTree(TreeNode *root) {
    int ans = 0;
    diameterOfBinaryTreeHelper(root, ans);
    return ans;
  }
};
// @lc code=end
