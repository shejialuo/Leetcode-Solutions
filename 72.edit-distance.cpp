/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] Edit Distance
 */

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));

    for (int i = 0; i <= word1.size(); i++) {
      dp[i][0] = i;
    }
    for (int j = 0; j <= word2.size(); j++) {
      dp[0][j] = j;
    }

    for (int i = 1; i <= word1.size(); i++) {
      for (int j = 1; j <= word2.size(); j++) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] =
              min<int>({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
        }
      }
    }
    return dp.back().back();
  }
};
// @lc code=end
