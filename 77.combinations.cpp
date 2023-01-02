/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] Combinations
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  void combineHelper(vector<int> &one, vector<vector<int>> &ans, int k, int n,
                     int start) {
    if (one.size() == k) {
      ans.push_back(one);
    }
    for (int i = start + 1; i <= n; ++i) {
      one.push_back(i);
      combineHelper(one, ans, k, n, i);
      one.pop_back();
    }
  }

public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans{};
    vector<int> one{};
    combineHelper(one, ans, k, n, 0);
    return ans;
  }
};
// @lc code=end
