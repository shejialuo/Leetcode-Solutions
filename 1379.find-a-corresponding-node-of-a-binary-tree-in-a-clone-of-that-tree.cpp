/*
 * @lc app=leetcode.cn id=1379 lang=cpp
 *
 * [1379] Find a Corresponding Node of a Binary Tree in a Clone of That Tree
 */

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
  void dfs(TreeNode *original, TreeNode *cloned, TreeNode *target,
           TreeNode **result) {
    if (original != nullptr) {
      if (original->val == target->val) {
        *result = cloned;
        return;
      }
      dfs(original->left, cloned->left, target, result);
      dfs(original->right, cloned->right, target, result);
    }
  }

public:
  TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned,
                          TreeNode *target) {
    TreeNode *result = nullptr;
    dfs(original, cloned, target, &result);
    return result;
  }
};
// @lc code=end
