/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
 */

#include <queue>
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
  TreeNode *helper(vector<int> &nums, int start, int end) {
    if (start > end) {
      return nullptr;
    }

    int maxNum = -1;
    int index = 0;
    for (int i = start; i <= end; ++i) {
      if (nums[i] > maxNum) {
        index = i;
        maxNum = nums[i];
      }
    }

    TreeNode *node = new TreeNode{maxNum};

    node->left = helper(nums, start, index - 1);
    node->right = helper(nums, index + 1, end);

    return node;
  }

public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return helper(nums, 0, nums.size() - 1);
  }
};
// @lc code=end
