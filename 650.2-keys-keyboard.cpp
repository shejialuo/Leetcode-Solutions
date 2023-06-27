/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int minSteps(int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 2; i < dp.size(); i++) {
      for (int j = i - 1; j >= 1; j--) {
        if (i % j == 0) {
          dp[i] = i / j + dp[j];
          break;
        }
      }
    }

    return dp.back();
  }
};
// @lc code=end
