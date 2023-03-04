/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  void combinationSum2Helper(int index, int sum, int target,
                             vector<int> &candidates, vector<int> &one,
                             vector<vector<int>> &ans) {
    if (sum == target) {
      ans.push_back(one);
      return;
    } else if (sum > target) {
      return;
    }

    for (int i = index; i < candidates.size(); ++i) {
      // Here, we should skip the one level same value node.
      if (i != index && candidates[i] == candidates[i - 1]) {
        continue;
      }

      one.push_back(candidates[i]);
      combinationSum2Helper(i + 1, sum + candidates[i], target, candidates, one,
                            ans);
      one.pop_back();
    }
  }

public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans{};
    vector<int> one{};
    combinationSum2Helper(0, 0, target, candidates, one, ans);
    return ans;
  }
};
// @lc code=end
