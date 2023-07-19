/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */

#include <stack>
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
private:
  /**
   * @brief The in-order sequence is a1 < a2 < a3 < ai < ... < aj < an.
   * we assume that ai is swapped with aj. Such. There would
   * be a1 < a2 < a3 < aj > ai+1 < ... aj-1 > ai. However, there would
   * be a corner case when i + 1 = j.
   *
   */
  void recoverTreeHelper(TreeNode *node, TreeNode *&pre, TreeNode *&p1,
                         TreeNode *&p2) {
    if (node != nullptr) {
      recoverTreeHelper(node->left, pre, p1, p2);
      if (pre != nullptr && pre->val > node->val) {
        if (p1 == nullptr) {
          p1 = pre;
        }
        p2 = node;
      }
      pre = node;
      recoverTreeHelper(node->right, pre, p1, p2);
    }
  }

  void recoverTreeIterative(TreeNode *root) {
    stack<TreeNode *> st{};
    TreeNode *ptr = root;
    TreeNode *p1 = nullptr, *p2 = nullptr;
    TreeNode *pre = nullptr;
    while (ptr != nullptr || !st.empty()) {
      while (ptr != nullptr) {
        st.push(ptr);
        ptr = ptr->left;
      }
      if (!st.empty()) {
        TreeNode *node = st.top();
        if (pre != nullptr) {
          if (pre->val > node->val) {
            if (p1 == nullptr) {
              p1 = pre;
            }
            p2 = node;
          }
        }
        pre = node;
        st.pop();
        ptr = node->right;
      }
    }
    swap(p1->val, p2->val);
  }

public:
  void recoverTree(TreeNode *root) {
    // recoverTreeIterative(root);
    TreeNode *pre = nullptr, *p1 = nullptr, *p2 = nullptr;
    recoverTreeHelper(root, pre, p1, p2);
    swap(p1->val, p2->val);
  }
};
// @lc code=end
