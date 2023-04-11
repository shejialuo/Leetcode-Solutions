/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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

/**
 * @details It is not difficult to implement this problem.
 * We use iterative pre-order
 *
 */
class BSTIterator {
private:
  stack<TreeNode *> st;

  void pushLeft(TreeNode *node) {
    while (node != nullptr) {
      st.push(node);
      node = node->left;
    }
  }

public:
  BSTIterator(TreeNode *root) { pushLeft(root); }

  int next() {
    TreeNode *current = st.top();
    st.pop();
    pushLeft(current->right);
    return current->val;
  }

  bool hasNext() { return !st.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
