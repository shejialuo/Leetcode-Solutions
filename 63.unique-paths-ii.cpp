/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

#include <vector>
using namespace std;

/*
  * In the question 62 unique-paths there are no obstacles
  * the idea is still simple enough.
*/

// @lc code=start
class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    size_t m = obstacleGrid.size();
    size_t n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int j = 0; j < n && obstacleGrid[0][j] == 0; ++j) {
      dp[0][j] = 1;
    }
    for (int i = 0; i < m && obstacleGrid[i][0] == 0; ++i) {
      dp[i][0] = 1;
    }
    for(int i = 1; i < m; ++i) {
      for(int j = 1; j < n; ++j) {
        if (obstacleGrid[i][j] == 1) continue;
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
      }
    }
    return dp[m - 1][n - 1];
  }
};
// @lc code=end

