/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] Coin Change
 */

#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int coinChange(vector<int> &coins, int amount) {

    vector<int> dp(amount + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= amount; ++i) {
      int minNum = numeric_limits<int>::max();
      for (int j = 0; j < coins.size(); ++j) {
        if (coins[j] > i) {
          continue;
        }
        if (dp[i - coins[j]] != -1)
          minNum = min(dp[i - coins[j]], minNum);
      }
      if (minNum != numeric_limits<int>::max()) {
        dp[i] = minNum + 1;
      }
    }

    return dp[amount];
  }
};
// @lc code=end
