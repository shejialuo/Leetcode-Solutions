/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] Invert Binary Tree
 */

#include <iostream>
#include <stack>
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
  void invertTreeIterative(TreeNode *node) {
    TreeNode *ptr = node;

    stack<TreeNode *> st{};

    while (ptr != nullptr || !st.empty()) {
      while (ptr != nullptr) {
        swap(ptr->left, ptr->right);
        st.push(ptr);
        ptr = ptr->left;
      }

      if (!st.empty()) {
        ptr = st.top()->right;
        st.pop();
      }
    }
  }

  void invertTreeHelper(TreeNode *node) {
    if (node != nullptr) {
      swap(node->left, node->right);
      invertTreeHelper(node->left);
      invertTreeHelper(node->right);
    }
  }

public:
  TreeNode *invertTree(TreeNode *root) {
    // Recursive
    // invertTreeHelper(root);
    invertTreeIterative(root);
    return root;
  }
};
// @lc code=end
