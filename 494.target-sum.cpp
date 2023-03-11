/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] Target Sum
 */

// TODO: Add dynamic programming solution

#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  int ans = 0;
  void helper(vector<int> &nums, int i, int sum, int target) {
    if (i == nums.size()) {
      if (sum == target) {
        ans++;
      }
    } else {
      helper(nums, i + 1, sum + nums[i], target);
      helper(nums, i + 1, sum - nums[i], target);
    }
  }

  /**
   * @brief The most important is to convert this problem to
   * ONLY consider about the plus. We assume that plus is x
   * And the delete is (sum - x). Thus we can get x - (sum - x) = target.
   * 2x = (target + sum), because x is integer, so target + sum
   * must be even. So we can only consider about the plus. And
   * convert this problem to 0-1 packing problem
   *
   */
  int dynamicProgramming(vector<int> &nums, int target) {
    int sum = accumulate(nums.cbegin(), nums.cend(), 0);
    if ((sum + target) % 2 != 0) {
      return 0;
    }
    if (sum < abs(target)) {
      return 0;
    }

    int weight = (sum + target) / 2;

    vector<int> dp(weight + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = weight; j >= nums[i]; j--) {
        dp[j] += dp[j - nums[i]];
      }
    }
    return dp.back();
  }

public:
  int findTargetSumWays(vector<int> &nums, int target) {
    // helper(nums, 0, 0, target);
    // return ans;
    return dynamicProgramming(nums, target);
  }
};
// @lc code=end
