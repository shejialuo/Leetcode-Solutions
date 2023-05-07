/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

#include <stack>
#include <vector>
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
public:
  vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> st;
    vector<int> ans{};
    while (root != nullptr || !st.empty()) {
      while (root != nullptr) {
        st.push(root);
        root = root->left;
      }

      if (!st.empty()) {
        TreeNode *node = st.top();
        ans.push_back(node->val);
        st.pop();
        root = node->right;
      }
    }
    return ans;
  }
};
// @lc code=end
