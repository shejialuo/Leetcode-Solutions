/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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

#include <limits>
#include <stack>
using namespace std;

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
private:
  bool isValidBSTHelper(TreeNode *&pre, TreeNode *node) {
    if (node != nullptr) {
      bool okLeft = isValidBSTHelper(pre, node->left);
      if (pre != nullptr && pre->val >= node->val) {
        return false;
      }
      pre = node;
      return okLeft && isValidBSTHelper(pre, node->right);
    }
    return true;
  }

  bool isValidBSTIterative(TreeNode *root) {
    stack<TreeNode *> st{};
    TreeNode *node = root;
    long maxNum = numeric_limits<long>::min();
    while (node != nullptr || !st.empty()) {
      while (node != nullptr) {
        st.push(node);
        node = node->left;
      }
      if (!st.empty()) {
        TreeNode *stackOnTop = st.top();
        st.pop();
        if (stackOnTop->val > maxNum) {
          maxNum = stackOnTop->val;
          node = stackOnTop->right;
        } else {
          return false;
        }
      }
    }
    return true;
  }

public:
  bool isValidBST(TreeNode *root) {
    TreeNode *pre = nullptr;
    return isValidBSTHelper(pre, root);
  }
};
// @lc code=end
