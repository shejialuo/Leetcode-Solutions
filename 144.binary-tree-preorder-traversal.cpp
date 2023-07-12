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
    TreeNode *ptr = root;
    while (ptr != nullptr || !st.empty()) {
      while (ptr != nullptr) {
        ans.push_back(ptr->val);
        st.push(ptr);
        ptr = ptr->left;
      }
      if (!st.empty()) {
        ptr = st.top()->right;
        st.pop();
      }
    }
    return ans;
  }
};
// @lc code=end
