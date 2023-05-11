/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int numDistinct(string s, string t) {
    vector<vector<unsigned long long>> dp(
        s.size() + 1, vector<unsigned long long>(t.size() + 1, 0));

    for (int i = 0; i <= s.size(); i++) {
      dp[i][0] = 1;
    }

    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < t.size(); j++) {
        if (s[i] == t[j]) {
          // We can delete and we can also do not delete the
          // current s, however, we could not delete t, so
          // we should always add j+1.
          dp[i + 1][j + 1] = dp[i][j] + dp[i][j + 1];
        } else {
          dp[i + 1][j + 1] = dp[i][j + 1];
        }
      }
    }

    return dp.back().back();
  }
};
// @lc code=end
