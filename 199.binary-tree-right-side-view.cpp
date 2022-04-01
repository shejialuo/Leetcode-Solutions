/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 */

#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

  void dfs(TreeNode* node, int depth, vector<int>& ans) {
    if(node != nullptr) {
      if(depth < ans.size()) {
        ans[depth] = node->val;
      } else {
        ans.emplace_back(node->val);
      }
      dfs(node->left, depth + 1, ans);
      dfs(node->right, depth + 1, ans);
    }
  }

  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans {};
    dfs(root, 0, ans);
    return ans;
  }
};
// @lc code=end

