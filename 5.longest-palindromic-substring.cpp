/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  /**
   * @brief Use dp to solve this problem
   *
   * @details dp[i][j] means the [i..j] substring of s
   * is the palindromic string. Then we could get the
   * recursive. dp[i][j] = dp[i+1][j-1] & s[i + 1] == s[j - 1].
   *
   * If we draw the table, we could easily find how to write the loop.
   *   0 1 2 3 4
   * 0 T x x x x
   * 1   T x x x
   * 2     T x x
   * 3       T x
   * 4         T
   *
   * And we need to think how to search, it is easy.
   * (4, 4)
   * (3, 4)
   * (3, 3)-> (2, 4)
   * (2, 3)-> (1, 4)
   * (2 ,2) -> (1, 3) -> (0, 4)
   * (1, 1) -> (0, 2)
   * (1, 2) -> (0, 3)
   * (0, 0)
   * (0 , 1)
   *
   * Thus, we could solve this problem.
   */
  string longestPalindromeDP(const string &s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

    int begin = 0, length = 1;
    bool direction = true;

    int start = s.size() - 1;

    while (start >= 0) {
      for (int i = 0; i < 2 && start + i < s.size(); i++) {
        int localStart = start, localEnd = start + i;
        while (localStart >= 0 && localEnd < s.size()) {
          if (localStart == localEnd) {
            dp[localStart][localEnd] = true;
          } else if (localStart + 1 == localEnd &&
                     s[localStart] == s[localEnd]) {
            dp[localStart][localEnd] = true;
          } else {
            dp[localStart][localEnd] = dp[localStart + 1][localEnd - 1] &&
                                       s[localStart] == s[localEnd];
          }

          if (dp[localStart][localEnd] && localEnd - localStart + 1 > length) {
            begin = localStart;
            length = localEnd - localStart + 1;
          }
          localStart--;
          localEnd++;
        }
      }
      start--;
    }
    return s.substr(begin, length);
  }

public:
  string longestPalindrome(string s) { return longestPalindromeDP(s); }
};
// @lc code=end
