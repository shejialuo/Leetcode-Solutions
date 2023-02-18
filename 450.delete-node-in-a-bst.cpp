/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] Delete Node in a BST
 */

// TODO: refactor the code

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
  TreeNode *deleteNode(TreeNode *root, int key) {
    TreeNode *ptr = root;

    TreeNode *aux = new TreeNode{-1};
    aux->left = root;
    TreeNode *parent = aux;

    while (ptr != nullptr) {
      if (ptr->val == key) {
        break;
      } else if (ptr->val > key) {
        parent = ptr;
        ptr = ptr->left;
      } else {
        parent = ptr;
        ptr = ptr->right;
      }
    }

    if (ptr != nullptr) {
      if (ptr->left == nullptr && ptr->right == nullptr) {
        if (parent->left == ptr) {
          parent->left = nullptr;
        } else {
          parent->right = nullptr;
        }
      } else if (ptr->left == nullptr) {
        if (parent->left == ptr) {
          parent->left = ptr->right;
        } else {
          parent->right = ptr->right;
        }
      } else if (ptr->right == nullptr) {
        if (parent->left == ptr) {
          parent->left = ptr->left;
        } else {
          parent->right = ptr->left;
        }
      } else {
        TreeNode *rightNode = ptr->right;

        TreeNode *minNode = rightNode;
        TreeNode *minNodeParent = nullptr;
        while (minNode->left != nullptr) {
          minNodeParent = minNode;
          minNode = minNode->left;
        }

        if (parent->left == ptr) {
          parent->left = minNode;
        } else {
          parent->right = minNode;
        }

        if (minNodeParent != nullptr) {
          minNodeParent->left = minNode->right;
          minNode->right = rightNode;
          minNode->left = ptr->left;
        } else {
          minNode->left = ptr->left;
        }
      }
      ptr->left = nullptr;
      ptr->right = nullptr;
    }

    root = aux->left;
    delete aux;

    return root;
  }
};
// @lc code=end
