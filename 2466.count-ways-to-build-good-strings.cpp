/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] Count Ways To Build Good Strings
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  const int M = 1000'000'007;

public:
  int countGoodStrings(int low, int high, int zero, int one) {
    vector<int> dp(high + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= high; i++) {
      if (i >= one) {
        dp[i] = (dp[i] + dp[i - one]) % M;
      }

      if (i >= zero) {
        dp[i] = (dp[i] + dp[i - zero]) % M;
      }
    }

    int ans = 0;
    for (int i = low; i <= high; i++) {
      ans = (ans + dp[i]) % M;
    }
    return ans;
  }
};
// @lc code=end
