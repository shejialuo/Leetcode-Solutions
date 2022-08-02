/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
 */

#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans{};
    stack<TreeNode*> st{};
    TreeNode* pre {};
    while(root || !st.empty()) {
      while(root) {
        st.push(root);
        root = root->left;
      }
      if(!st.empty()) {
        TreeNode* node = st.top();
        if(node->right == nullptr || node->right == pre) {
          ans.push_back(node->val);
          pre = node;
          st.pop();
        } else {
          root = node->right;
        }
      }
    }
    return ans;
  }
};
// @lc code=end

