/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */

#include <ios>
#include <unordered_map>
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
  TreeNode *buildTreeHelper(unordered_map<int, int> &table,
                            vector<int> &postorder, int inorderStart,
                            int inorderEnd, int &postorderEnd) {
    if (inorderStart > inorderEnd) {
      return nullptr;
    }

    int root = postorder[postorderEnd--];

    TreeNode *node = new TreeNode{root};

    int index = table[root];

    // Here, we must handle the right first, because the postorder order
    // is leftTree, rightTree. Until we handle all the rightTree we could
    // handle leftTree.
    node->right =
        buildTreeHelper(table, postorder, index + 1, inorderEnd, postorderEnd);

    node->left = buildTreeHelper(table, postorder, inorderStart, index - 1,
                                 postorderEnd);

    return node;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    unordered_map<int, int> table{};

    for (int i = 0; i < inorder.size(); ++i) {
      table[inorder[i]] = i;
    }

    int postorderSize = postorder.size() - 1;

    return buildTreeHelper(table, postorder, 0, inorder.size() - 1,
                           postorderSize);
  }
};
// @lc code=end
