/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[0][2] = 0;
    dp[0][3] = -prices[0];
    dp[0][4] = 0;

    for (int i = 1; i < prices.size(); i++) {
      dp[i][0] = dp[i - 1][0];
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
      dp[i][2] = max({dp[i - 1][2], dp[i - 1][1] + prices[i], dp[i][0]});
      dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
      dp[i][4] = max({dp[i - 1][4], dp[i - 1][3] + prices[i], dp[i][2]});
    }

    return max(
        {dp.back()[0], dp.back()[1], dp.back()[2], dp.back()[3], dp.back()[4]});
  }
};
// @lc code=end
