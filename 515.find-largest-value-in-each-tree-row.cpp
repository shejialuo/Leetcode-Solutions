/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 */

#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<int> largestValues(TreeNode* root) {
    queue<TreeNode*> qu;
    vector<int> ans{};
    if(root != nullptr) {
      qu.push(root);
    }
    while(!qu.empty()) {
      int lengthOfRow = qu.size();
      int largest = numeric_limits<int>::min();
      for(int i = 0; i < lengthOfRow; ++i) {
        TreeNode* node = qu.front();
        largest = max(largest, node->val);
        if(node->left != nullptr) {
          qu.push(node->left);
        }
        if(node->right != nullptr) {
          qu.push(node->right);
        }
        qu.pop();
      }
      ans.push_back(largest);
    }
    return ans;
  }
};
// @lc code=end

