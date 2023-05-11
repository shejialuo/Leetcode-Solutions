/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  /**
   * @brief State dp, for a digit, it could have the following
   * state, delete or not delete, is plus or minus.
   *
   * @param nums
   * @return int
   */
  int wiggleMaxLengthDP(vector<int> &nums) {
    vector<vector<vector<int>>> dp(nums.size(),
                                   vector<vector<int>>(2, vector<int>(2)));

    dp[0][0][0] = 1;
    dp[0][0][1] = 1;
    dp[0][1][0] = 0;
    dp[0][1][1] = 0;

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] - nums[i - 1] > 0) {
        dp[i][0][0] = max(dp[i - 1][1][1], dp[i - 1][0][1]) + 1;
        dp[i][0][1] = 1;
      } else if (nums[i] - nums[i - 1] < 0) {
        dp[i][0][0] = 1;
        dp[i][0][1] = max(dp[i - 1][0][0], dp[i - 1][1][0]) + 1;
      } else if (nums[i] == nums[i - 1]) {
        dp[i][0][0] = 1;
        dp[i][0][1] = 1;
      }
      dp[i][1][0] = max(dp[i - 1][0][0], dp[i - 1][1][0]);
      dp[i][1][1] = max(dp[i - 1][0][1], dp[i - 1][1][1]);
    }

    return max<int>(
        {dp.back()[0][0], dp.back()[0][1], dp.back()[1][0], dp.back()[1][1]});
  }

public:
  int wiggleMaxLength(vector<int> &nums) { return wiggleMaxLengthDP(nums); }
};
// @lc code=end
