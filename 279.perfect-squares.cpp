/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int numSquares(int n) {
    vector<int> squares{};
    for (int i = 1; i <= 100; ++i) {
      squares.push_back(i * i);
    }

    vector<int> dp(n + 1, numeric_limits<int>::max());
    dp[0] = 0;

    for (int i = 0; i < squares.size(); ++i) {
      for (int j = squares[i]; j <= n; ++j) {
        if (dp[j - squares[i]] != numeric_limits<int>::max()) {
          dp[j] = min(dp[j], dp[j - squares[i]] + 1);
        }
      }
    }

    return dp.back();
  }
};
// @lc code=end
