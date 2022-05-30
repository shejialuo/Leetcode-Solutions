/*
 * @lc app=leetcode.cn id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 */

#include <vector>
#include <algorithm>
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
  void helper(TreeNode* node, vector<int>& leaf) {
    if(node != nullptr) {
      if(node->left == nullptr && node->right == nullptr) {
        leaf.push_back(node->val);
      }
      helper(node->left, leaf);
      helper(node->right, leaf);
    }
  }
public:
  bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    vector<int> leaf1 {}, leaf2{};
    helper(root1, leaf1);
    helper(root2, leaf2);
    return leaf1 == leaf2;
  }
};
// @lc code=end

