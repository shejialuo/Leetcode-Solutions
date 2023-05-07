/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] Pseudo-Palindromic Paths in a Binary Tree
 */

#include <unordered_map>
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

#include <vector>
using namespace std;

class Solution {
private:
  void pseudoPalindromicPathsHelper(TreeNode *node, int count, int &ans) {
    if (node != nullptr) {

      // Use xor to represent the frequency
      // Bit manipulation
      count ^= (1 << node->val);

      if (node->left == nullptr && node->right == nullptr) {
        // We only allow one '1' in the count
        if (count == 0 || (count & (count - 1)) == 0) {
          ans++;
        }
      }

      pseudoPalindromicPathsHelper(node->left, count, ans);
      pseudoPalindromicPathsHelper(node->right, count, ans);
    }
  }

public:
  int pseudoPalindromicPaths(TreeNode *root) {
    int ans = 0;
    pseudoPalindromicPathsHelper(root, 0, ans);
    return ans;
  }
};
// @lc code=end
