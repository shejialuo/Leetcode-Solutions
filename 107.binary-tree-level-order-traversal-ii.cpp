/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 */

#include <algorithm>
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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> ans{};
    if (root == nullptr) {
      return ans;
    }
    queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty()) {
      int levelLength = qu.size();
      vector<int> levelNode{};
      for (int i = 0; i < levelLength; ++i) {
        TreeNode *node = qu.front();
        qu.pop();
        levelNode.push_back(node->val);
        if (node->left != nullptr) {
          qu.push(node->left);
        }
        if (node->right != nullptr) {
          qu.push(node->right);
        }
      }
      ans.push_back(std::move(levelNode));
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
