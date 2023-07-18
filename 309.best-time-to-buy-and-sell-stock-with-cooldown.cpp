/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(4, 0));

    dp[0][2] = -prices[0];

    for (int i = 1; i < prices.size(); i++) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = dp[i - 1][2] + prices[i];
      dp[i][2] = max(dp[i - 1][2], dp[i - 1][0] - prices[i]);
    }

    return max(max(dp.back()[0], dp.back()[1]), dp.back()[2]);
  }
};
// @lc code=end
