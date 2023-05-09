/*
 * @lc app=leetcode.cn id=552 lang=cpp
 *
 * [552] Student Attendance Record II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  const unsigned int M = 1000000007;

public:
  /**
   * @brief This is a hard question, we should split the state carefully
   * and think the state transition
   *
   * dp[i][0]: with one A, and two tailing L
   * dp[i][1]: with one A, and one tailing L
   *
   * dp[i][2]: with no A,  and two tailing L
   * dp[i][3]: with no A , and one tailing L
   *
   * dp[i][4]: with one A, and other situation
   * dp[i][5]: with no A , and other situation
   *
   * dp[i - 1][0] could only add P to dp[i][4]
   *
   * dp[i - 1][1] could add L to dp[i][0]
   *                    add P to dp[i][4]
   *
   * dp[i - 1][3] could add L to dp[i][2]
   *              could add A to dp[i][4]
   *              could add P to dp[i][5]
   *
   * dp[i - 1][4] could add L to dp[i][1]
   *              could add P to dp[i][4]
   *
   * dp[i - 1][5] could add A to dp[i][4]
   *              could add L to dp[i][3]
   *              could add P to dp[i][5]
   *
   */
  int checkRecord(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(6, 0));

    dp[0][5] = 1;

    for (int i = 1; i <= n; i++) {

      dp[i][4] = (dp[i][4] + dp[i - 1][0]) % M;

      dp[i][0] = (dp[i][0] + dp[i - 1][1]) % M;
      dp[i][4] = (dp[i][4] + dp[i - 1][1]) % M;

      dp[i][4] = (dp[i][4] + dp[i - 1][2]) % M;
      dp[i][5] = (dp[i][5] + dp[i - 1][2]) % M;

      dp[i][2] = (dp[i][2] + dp[i - 1][3]) % M;
      dp[i][4] = (dp[i][4] + dp[i - 1][3]) % M;
      dp[i][5] = (dp[i][5] + dp[i - 1][3]) % M;

      dp[i][1] = (dp[i][1] + dp[i - 1][4]) % M;
      dp[i][4] = (dp[i][4] + dp[i - 1][4]) % M;

      dp[i][4] = (dp[i][4] + dp[i - 1][5]) % M;
      dp[i][3] = (dp[i][3] + dp[i - 1][5]) % M;
      dp[i][5] = (dp[i][5] + dp[i - 1][5]) % M;
    }

    int ans = 0;
    for (int i = 0; i < dp.back().size(); i++) {
      ans = (ans + dp.back()[i]) % M;
    }

    return ans;
  }
};
// @lc code=end
