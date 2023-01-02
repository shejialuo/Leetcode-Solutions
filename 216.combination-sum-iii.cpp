/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] Combination Sum III
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  void combinationSum3Helper(int start, int sum, int k, vector<int> &one,
                             vector<vector<int>> &ans) {
    if (one.size() == k && sum == 0) {
      ans.push_back(one);
      return;
    }

    for (int i = start + 1; i <= 9; ++i) {
      one.push_back(i);
      combinationSum3Helper(i, sum - i, k, one, ans);
      one.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ans{};
    vector<int> one{};
    combinationSum3Helper(0, n, k, one, ans);
    return ans;
  }
};
// @lc code=end
