/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
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
  void findModeHelper(TreeNode *node, int &previous, int &frequency, int &count,
                      vector<int> &ans) {
    if (node != nullptr) {
      findModeHelper(node->left, previous, frequency, count, ans);

      if (previous == -10001) {
        count = 1;
      } else if (node->val == previous) {
        count++;
      } else {
        count = 1;
      }

      if (count == frequency) {
        ans.push_back(node->val);
      } else if (count > frequency) {
        ans.clear();
        ans.push_back(node->val);
        frequency = count;
      }
      previous = node->val;
      findModeHelper(node->right, previous, frequency, count, ans);
    }
  }

public:
  vector<int> findMode(TreeNode *root) {
    vector<int> ans{};
    int frequency = 0;
    int previous = -10001;
    int count = 0;
    findModeHelper(root, previous, frequency, count, ans);
    return ans;
  }
};
// @lc code=end
