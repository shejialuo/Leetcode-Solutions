/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] Average of Levels in Binary Tree
 */

#include <queue>
#include <vector>
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
  vector<double> averageOfLevels(TreeNode *root) {
    queue<TreeNode *> qu;
    vector<double> ans{};
    if (root != nullptr) {
      qu.push(root);
    }
    while (!qu.empty()) {
      int size = qu.size();
      long sum = 0;
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
      ans.push_back(static_cast<double>(sum) / static_cast<double>(size));
    }
    return ans;
  }
};
// @lc code=end
