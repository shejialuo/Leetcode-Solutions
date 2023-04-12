/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
 */

#include <unordered_set>
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
private:
  void delNodesHelper(TreeNode *node, TreeNode *parent, unordered_set<int> &del,
                      vector<TreeNode *> &ans) {
    if (node != nullptr) {
      delNodesHelper(node->left, node, del, ans);
      delNodesHelper(node->right, node, del, ans);

      if (del.count(node->val) != 0) {
        if (parent != nullptr) {
          if (parent->left == node) {
            parent->left = nullptr;
          } else {
            parent->right = nullptr;
          }
        }
        if (node->left != nullptr) {
          ans.push_back(node->left);
        }
        if (node->right != nullptr) {
          ans.push_back(node->right);
        }
      }
    }
  }

public:
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    vector<TreeNode *> ans{};
    unordered_set<int> del(to_delete.cbegin(), to_delete.cend());
    delNodesHelper(root, nullptr, del, ans);

    // special case: when deleting the root.
    if (del.count(root->val) == 0) {
      ans.push_back(root);
    }

    return ans;
  }
};
// @lc code=end
