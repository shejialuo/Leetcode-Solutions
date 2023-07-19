/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] Path Sum III
 */

#include <unordered_map>
using namespace std;

/*
 * Actually, we could brute-forcedly solve this question,
 * just use dfs for every subTree. However, there would
 * be many overlaps.
 *
 * So use dynamic programming just remember the prefix we
 * add. Simple idea.
 */

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
  unordered_map<long, int> prefix{};
  int pathSumHelper(TreeNode *node, long sum, int targetSum) {
    if (node != nullptr) {
      int ans = 0;
      sum += node->val;
      ans += prefix[sum - targetSum];

      prefix[sum]++;
      ans += pathSumHelper(node->left, sum, targetSum);
      ans += pathSumHelper(node->right, sum, targetSum);
      prefix[sum]--;
      sum -= node->val;
      return ans;
    }
    return 0;
  }

public:
  int pathSum(TreeNode *root, int targetSum) {
    prefix[0] = 1;
    return pathSumHelper(root, 0, targetSum);
  }
};
// @lc code=end
