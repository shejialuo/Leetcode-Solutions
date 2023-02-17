/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 */

#include <array>
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
  void dfs(TreeNode *node, array<int, 100> &path, vector<string> &ans,
           int &num) {
    if (node != nullptr) {
      path[num] = node->val;
      if (node->left == nullptr && node->right == nullptr) {
        string s{};
        for (int i = 0; i < num; ++i) {
          s += to_string(path[i]) + "->";
        }
        s += to_string(path[num]);
        ans.push_back(s);
      }
      num++;
      dfs(node->left, path, ans, num);
      dfs(node->right, path, ans, num);
      num--;
    }
  }

  vector<string> binaryTreePaths(TreeNode *root) {
    array<int, 100> path{};
    vector<string> ans{};
    int num = 0;
    dfs(root, path, ans, num);
    return ans;
  }
};
// @lc code=end
