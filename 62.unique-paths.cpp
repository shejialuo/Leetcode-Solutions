/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] Unique Paths
 */


// @lc code=start
class Solution {
public:
  void helper(int i, int j, int m, int n, int &ans) {
      if (i >= m || j >= n) return;
      if (i == m - 1 && j == n -1) ans++;
      helper(i + 1, j, m, n, ans);
      helper(i, j + 1, m, n, ans);
  }
  // Here, I use a brute force way to get the answer.
  // It must be out-of-time.
  int uniquePathsBruteForce(int m, int n) {
    int ans = 0;
    helper(0, 0, m, n, ans);
    return ans;
  }

  // However, we should use a clever way to solve this problem
  // We will consume so many repeat calculations. Use DP
  // dp[m][n] = dp[m][n - 1] + dp[m - 1][n]
  int uniquePathsDynamicProgramming(int m, int n) {
    int dp[m][n];
    for (int j = 0; j < n; ++j) {
      dp[0][j] = 1;
    }
    for (int i = 0; i < m; ++i) {
      dp[i][0] = 1;
    }
    for(int i = 1; i < m; ++i) {
      for(int j = 1; j < n; ++j) {
        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
      }
    }
    return dp[m - 1][n - 1];
  }

  int uniquePaths(int m, int n) {
    return uniquePathsDynamicProgramming(m, n);
  }
};
// @lc code=end

