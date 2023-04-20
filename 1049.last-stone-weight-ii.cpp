/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

#include <numeric>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief It may seem this problem is difficult for us to
   * solve, however, we should convert the problem, in the
   * original problem, we only have 1 which means we need to
   * use every stone. So we could think the way to convert this
   * problem. We divide the stone to be two part, which makes
   * them near the median. Thus the value must be minimal. And
   * also we make it to be 0/1.
   *
   * However, this is too difficult to convert the problem into
   * 0/1 packing problem.
   */
  int lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.cbegin(), stones.cend(), 0);
    int target = sum / 2;

    vector<int> dp(target + 1, 0);

    for (int i = 0; i < stones.size(); i++) {
      for (int j = target; j >= stones[i]; j--) {
        dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }

    return (sum - dp[target]) - dp[target];
  }
};
// @lc code=end
