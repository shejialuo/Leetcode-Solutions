/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] Word Break
 */

#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief We set dp[i] to the (0, i) of s can be break.
   * dp[j] = (i + 1, j) is in dict && dp[i]. And the most
   * difficult thing is how to convert this into complete
   * packing problem.
   *
   */
  bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> words(wordDict.cbegin(), wordDict.cend());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        string word = s.substr(j, i - j);
        if (words.count(word) && dp[j]) {
          dp[i] = true;
        }
      }
    }
    return dp.back();
  }
};
// @lc code=end
