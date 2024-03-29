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
  void combineHelper(vector<int> &one, vector<vector<int>> &ans, int i, int k,
                     int n, int start) {
    if (i == k) {
      ans.push_back(one);
      return;
    }

    for (int index = start + 1; index + k - 1 - i <= n; index++) {
      one[i] = index;
      combineHelper(one, ans, i + 1, k, n, index);
    }
  }

public:
  vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans{};
    vector<int> one(k, 0);
    combineHelper(one, ans, 0, k, n, 0);
    return ans;
  }
};
// @lc code=end
