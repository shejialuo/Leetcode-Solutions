/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief This question is the LCS question. We define dp
   * as the following: dp[i][j] means the ith and jth minimum
   * number of steps. It's important to use the LCS pattern.
   * Well, maybe a pattern!
   *
   */
  int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

    for (int i = 0; i <= word1.size(); i++) {
      dp[i][0] = i;
    }

    for (int i = 0; i <= word2.size(); i++) {
      dp[0][i] = i;
    }

    for (int i = 0; i < word1.size(); i++) {
      for (int j = 0; j < word2.size(); j++) {
        if (word1[i] == word2[j]) {
          dp[i + 1][j + 1] = dp[i][j];
        } else {
          // We could reduce it to
          // dp[i + 1][j + 1] = min(dp[i][j + 1] + 1, dp[i + 1][j] + 1).
          // However, I like the following.
          dp[i + 1][j + 1] =
              min<int>({dp[i][j] + 2, dp[i][j + 1] + 1, dp[i + 1][j] + 1});
        }
      }
    }

    return dp.back().back();
  }
};
// @lc code=end
