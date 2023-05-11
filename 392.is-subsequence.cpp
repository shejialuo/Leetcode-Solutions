/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  bool isSubsequenceTwoPointer(const string &s, const string &t) {
    int p1 = 0, p2 = 0;

    for (char c : s) {
      while (p1 < t.size() && t[p1] != c) {
        p1++;
      }
      if (p1 == t.size()) {
        return false;
      }
      p1++;
    }
    return true;
  }

  bool isSubsequenceDP(const string &s, const string &t) {
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

    for (int i = 0; i < s.size(); i++) {
      for (int j = 0; j < t.size(); j++) {
        if (s[i] == t[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        } else {
          // Here, we can only delete the t, this is the
          // big difference.
          dp[i + 1][j + 1] = dp[i + 1][j];
        }
      }
    }

    return dp.back().back() == s.size();
  }

public:
  bool isSubsequence(string s, string t) { return isSubsequenceDP(s, t); }
};
// @lc code=end
