/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] Path Sum II
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
private:
  vector<vector<int>> ans{};

public:
  void dfs(TreeNode *node, vector<int> &path, int &targetSum, int sum) {
    if (node != nullptr) {
      sum += node->val;
      path.push_back(node->val);
      if (node->left == nullptr && node->right == nullptr) {
        if (sum == targetSum) {
          ans.push_back(path);
        }
      }
      dfs(node->left, path, targetSum, sum);
      dfs(node->right, path, targetSum, sum);
      path.pop_back();
    }
  }

  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    vector<int> path{};
    dfs(root, path, targetSum, 0);
    return ans;
  }
};
// @lc code=end
