/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] Coin Change II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief This is a complete packing problem. We could
   * abstract the idea into how to find the way to complete
   * the `amount` weight of the bag. We could easily get an idea.
   * dp[j] += dp[j - coins[i]].
   *
   */
  int change(int amount, vector<int> &coins) {
    vector<int> dp(amount + 1, 0);

    dp[0] = 1;

    // Here, we must traverse the item first,
    // thus we use combination, this is because
    // we use the item sequentially.
    for (int i = 0; i < coins.size(); ++i) {
      for (int j = coins[i]; j <= amount; ++j) {
        dp[j] += dp[j - coins[i]];
      }
    }

    return dp[amount];
  }
};
// @lc code=end
