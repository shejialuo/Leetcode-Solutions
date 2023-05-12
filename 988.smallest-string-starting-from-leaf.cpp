/*
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] Smallest String Starting From Leaf
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

#include <algorithm>
#include <string>
using namespace std;

class Solution {
private:
  void smallestFromLeafHelper(TreeNode *node, string &path, string &ans) {
    if (node != nullptr) {
      path.push_back(node->val + 'a');
      if (node->left == nullptr && node->right == nullptr) {
        ans = min(string{path.crbegin(), path.crend()}, ans);
      }
      smallestFromLeafHelper(node->left, path, ans);
      smallestFromLeafHelper(node->right, path, ans);
      path.pop_back();
    }
  }

public:
  string smallestFromLeaf(TreeNode *root) {
    string ans{"~"};
    string path{};
    smallestFromLeafHelper(root, path, ans);
    return ans;
  }
};
// @lc code=end
