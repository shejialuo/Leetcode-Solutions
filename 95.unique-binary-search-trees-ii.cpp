/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

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
  /**
   * @brief We need to think the way to cleverly solve this problem. for a value
   * node called `i`. We are sure that [1.. i - 1] is in the left subtree and [i
   * + 1.. n] is in the right subtree. And this two problem is the subproblem.
   * we use divide and conquer to solve this problem
   *
   */
  vector<TreeNode *> generateTreesHelper(int start, int end) {
    if (start > end) {
      return {nullptr};
    }

    vector<TreeNode *> root;

    for (int i = start; i <= end; i++) {
      vector<TreeNode *> leftSubTrees = generateTreesHelper(start, i - 1);
      vector<TreeNode *> rightSubTrees = generateTreesHelper(i + 1, end);

      for (auto &&leftSubTree : leftSubTrees) {
        for (auto &&rightSubTree : rightSubTrees) {
          TreeNode *node = new TreeNode{i};
          node->left = leftSubTree;
          node->right = rightSubTree;
          root.push_back(node);
        }
      }
    }
    return root;
  }

public:
  vector<TreeNode *> generateTrees(int n) { return generateTreesHelper(1, n); }
};
// @lc code=end
