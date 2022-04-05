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
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <stack>
#include <limits>
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  bool isValidBST(TreeNode* root) {
    stack<TreeNode*> st{};
    TreeNode* node = root;
    long maxNum = numeric_limits<long>::min();
    while(node != nullptr || !st.empty()){
      while(node != nullptr) {
        st.push(node);
        node = node->left;
      }
      if(!st.empty()) {
        TreeNode* stackOnTop = st.top();
        st.pop();
        if(stackOnTop->val > maxNum) {
          maxNum = stackOnTop->val;
          node = stackOnTop->right;
        } else {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end

