/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] House Robber II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  int robRange(vector<int> &nums, vector<int> &dp, int start, int end) {

    if (start == end) {
      return nums[start];
    }

    dp[0] = nums[start];
    dp[1] = max(nums[start], nums[start + 1]);

    for (int i = 2; i < dp.size(); i++) {
      dp[i] = max(dp[i - 2] + nums[start + i], dp[i - 1]);
    }

    return dp.back();
  }

public:
  /**
   * @brief When adding the circle, we could break the circle
   * to convert the problem to House Robber I
   *
   */
  int rob(vector<int> &nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    vector<int> dp(nums.size() - 1, 0);

    int resultLeft = robRange(nums, dp, 0, nums.size() - 2);
    int resultRight = robRange(nums, dp, 1, nums.size() - 1);
    return max(resultLeft, resultRight);
  }
};
// @lc code=end
