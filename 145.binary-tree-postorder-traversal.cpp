/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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

/*
 * The most difficult part is how should we access the node
 * itself. There are two situations:
 *
 * 1. If the node is a leaf, we should access it.
 * 2. We have traversed the right subtree.
 *
 * For the situation 1, it is easy, but how to indicate we
 * have traversed the right subtree. We could use an extra
 * node to indicate the last time we have visited.
 *
 */

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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans{};
    stack<TreeNode *> st{};
    TreeNode *pre{nullptr}, *ptr = root;
    while (ptr != nullptr || !st.empty()) {
      while (ptr != nullptr) {
        st.push(ptr);
        ptr = ptr->left;
      }

      if (!st.empty()) {
        TreeNode *cur = st.top();
        if (cur->right == nullptr || cur->right == pre) {
          ans.push_back(cur->val);
          pre = cur;
          st.pop();
        } else {
          ptr = cur->right;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
