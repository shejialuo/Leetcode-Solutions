/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

#include <vector>
using namespace std;

/**
 * @brief It is easy to solve this question, we use `dp[i]`
 * to indicate that it is the minumum cost for climbing ith stairs.
 *
 * dp[0] = 0, dp[1] = 0, dp[2] = min(dp[0]+cost[0], dp[1] + cost[1])
 * dp[3] = min(dp[1] + cost[1], dp[2] + cost[2])
 *
 * dp[n] = min(dp[n - 2] + cost[n -2], dp[n - 1] + cost[n - 1]);
 */

// @lc code=start
class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size() + 1, 0);
    for (int i = 2; i <= cost.size(); ++i) {
      dp[i] = min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
    }
    return dp[cost.size()];
  }
};
// @lc code=end

