/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] Even Odd Tree
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

#include <limits>
#include <queue>
using namespace std;

class Solution {
public:
  bool isEvenOddTree(TreeNode *root) {
    int index = 0;
    queue<TreeNode *> qu{};

    if (root != nullptr) {
      qu.push(root);
    }

    while (!qu.empty()) {
      int size = qu.size();
      int prev = index % 2 == 0 ? numeric_limits<int>::min()
                                : numeric_limits<int>::max();
      for (int i = 0; i < size; i++) {
        TreeNode *node = qu.front();
        if (index % 2 == 0) {
          if (node->val % 2 == 0 || node->val <= prev) {
            return false;
          }

        } else {
          if (node->val % 2 != 0 || node->val >= prev) {
            return false;
          }
        }

        prev = node->val;

        if (node->left) {
          qu.push(node->left);
        }

        if (node->right) {
          qu.push(node->right);
        }
        qu.pop();
      }
      index++;
    }
    return true;
  }
};
// @lc code=end
