/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] Construct String from Binary Tree
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

#include <string>
using namespace std;

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
  void tree2strHelper(TreeNode *node, string &s) {
    s.append(to_string(node->val));
    if (node->left != nullptr) {
      s.append("(");
      tree2strHelper(node->left, s);
      s.append(")");
    }
    if (node->right != nullptr) {
      node->left == nullptr ? s.append("()(") : s.append("(");
      tree2strHelper(node->right, s);
      s.append(")");
    }
  }

public:
  string tree2str(TreeNode *root) {
    string ans{};
    tree2strHelper(root, ans);
    return ans;
  }
};
// @lc code=end
