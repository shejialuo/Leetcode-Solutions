/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include <vector>
using namespace std;

/*
 * This is a combination problem. So we need to use an index
 * to make sure that the answer is unique. When we have searched
 * all the possible of one value, we should drop it (this is what
 * index has done).
 *
 * For the other part, it is common. Just search all the
 * possible branches.
 */

// @lc code=start
class Solution {
private:
  vector<vector<int>> ans{};
  vector<int> combination{};
  void combinationSumHelper(vector<int> &candidates, int index, int sum,
                            int target) {

    if (sum == target) {
      ans.push_back(combination);
    }

    for (int i = index; i < candidates.size(); i++) {
      if (sum + candidates[i] <= target) {
        combination.push_back(candidates[i]);
        combinationSumHelper(candidates, i, sum + candidates[i], target);
        combination.pop_back();
      }
    }
  }

public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    combinationSumHelper(candidates, 0, 0, target);
    return ans;
  }
};
// @lc code=end
