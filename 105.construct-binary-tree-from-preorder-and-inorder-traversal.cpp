/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 */

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
  unordered_map<int, int> table{};

  TreeNode *buildTreeHelper(vector<int> &preorder, vector<int> &inorder,
                            int inorderStart, int inorderEnd,
                            int &preorderIndex) {
    if (inorderStart > inorderEnd) {
      return nullptr;
    }

    int root = preorder[preorderIndex];
    int index = table[root];

    TreeNode *node = new TreeNode{root};
    preorderIndex++;

    node->left = buildTreeHelper(preorder, inorder, inorderStart, index - 1,
                                 preorderIndex);
    node->right = buildTreeHelper(preorder, inorder, index + 1, inorderEnd,
                                  preorderIndex);

    return node;
  }

public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
      table[inorder[i]] = i;
    }

    int preorderIndex = 0;
    return buildTreeHelper(preorder, inorder, 0, inorder.size() - 1,
                           preorderIndex);
  }
};
// @lc code=end
