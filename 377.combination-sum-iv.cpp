/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

#include <limits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief This is a complete packing problem. For nums = [1,2,3]
   * target = 4, we could see the amount is target, and the items
   * are 1 2 3. Thus we could use the same idea as 518.coin-change-ii.cpp.
   * But the tricky thing is we should find the permutation not combination.
   *
   */
  int combinationSum4(vector<int> &nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for (int j = 0; j <= target; ++j) {
      for (int i = 0; i < nums.size(); ++i) {
        if (j >= nums[i] &&
            dp[j] < numeric_limits<int>::max() - dp[j - nums[i]]) {
          dp[j] += dp[j - nums[i]];
        }
      }
    }
    return dp.back();
  }
};
// @lc code=end
