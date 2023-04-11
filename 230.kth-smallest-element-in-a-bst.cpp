/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
 */

#include <stack>

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
  int kthSmallest(TreeNode *root, int k) {
    std::stack<TreeNode *> st{};
    TreeNode *ptr = root;

    int i = 0;
    while (ptr != nullptr || !st.empty()) {
      while (ptr != nullptr) {
        st.push(ptr);
        ptr = ptr->left;
      }

      if (!st.empty()) {
        i++;
        if (i == k) {
          return st.top()->val;
        }
        ptr = st.top()->right;
        st.pop();
      }
    }
    return -1;
  }
};
// @lc code=end
