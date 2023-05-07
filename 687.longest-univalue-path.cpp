/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
#include <utility>
using namespace std;

class Solution {
private:
  pair<int, int> longestUnivaluePathHelper(TreeNode *node, int &ans) {
    if (node != nullptr) {
      auto [leftValue, numLeft] = longestUnivaluePathHelper(node->left, ans);
      auto [rightValue, numRight] = longestUnivaluePathHelper(node->right, ans);

      int current = node->val;

      if (current != leftValue && current != rightValue) {
        return make_pair(current, 1);
      }

      int num = 0;
      int next = 0;

      if (current == leftValue) {
        num += numLeft;
        next = max(next, numLeft);
      }

      if (current == rightValue) {
        num += numRight;
        next = max(next, numRight);
      }

      ans = max(ans, num);

      return make_pair(current, next + 1);
    }

    return make_pair(-1001, -1);
  }

public:
  int longestUnivaluePath(TreeNode *root) {
    int ans = 0;
    longestUnivaluePathHelper(root, ans);
    return ans;
  }
};
// @lc code=end
