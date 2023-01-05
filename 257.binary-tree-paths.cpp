/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

#include <string>
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
  void dfs(TreeNode *node, vector<int> &path, vector<string> &ans) {
    if (node != nullptr) {
      path.push_back(node->val);
      if (node->left == nullptr && node->right == nullptr) {
        string s{};
        for (int i = 0; i < path.size() - 1; ++i) {
          s += to_string(path[i]) + "->";
        }
        s += to_string(path[path.size() - 1]);
        ans.push_back(s);
      }
      dfs(node->left, path, ans);
      dfs(node->right, path, ans);
      path.pop_back();
    }
  }

  vector<string> binaryTreePaths(TreeNode *root) {
    vector<int> path{};
    vector<string> ans{};
    dfs(root, path, ans);
    return ans;
  }
};
// @lc code=end
