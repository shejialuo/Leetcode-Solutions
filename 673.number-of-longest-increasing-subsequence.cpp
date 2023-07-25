/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(2, 1));

    int maxLength = 1, frequency = 1;

    for (int i = 1; i < nums.size(); i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] > nums[j]) {

          if (dp[j][0] + 1 > dp[i][0]) {
            dp[i][1] = dp[j][1];
          } else if (dp[j][0] + 1 == dp[i][0]) {
            dp[i][1] += dp[j][1];
          }

          dp[i][0] = max(dp[j][0] + 1, dp[i][0]);
        }
      }
      if (dp[i][0] > maxLength) {
        maxLength = dp[i][0];
        frequency = dp[i][1];
      } else if (dp[i][0] == maxLength) {
        frequency += dp[i][1];
      }
    }

    return frequency;
  }
};
// @lc code=end
