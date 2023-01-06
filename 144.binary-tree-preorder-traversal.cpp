/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans{};
    stack<TreeNode *> st;
    while (root != nullptr || !st.empty()) {
      while (root != nullptr) {
        ans.push_back(root->val);
        st.push(root);
        root = root->left;
      }
      if (!st.empty()) {
        TreeNode *node = st.top();
        root = node->right;
        st.pop();
      }
    }
    return ans;
  }
};
// @lc code=end
