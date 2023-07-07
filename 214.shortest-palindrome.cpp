/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

#include <algorithm>
#include <string>
#include <type_traits>
using namespace std;

// TODO: refactor

// @lc code=start
class Solution {
private:
  bool isPalindrome(const string &s, int end) {
    int start = 0;
    while (start < end) {
      if (s[start] != s[end]) {
        return false;
      }
      start++;
      end--;
    }
    return true;
  }

public:
  /**
   * @brief For this problem, we need to find the
   * longest palindrome index, and we could easily
   * solve this problem, the idea is simple if we
   * use brute force, but the clever way is to use
   * KMP.
   *
   */
  string shortestPalindrome(string s) {
    int end = s.size() - 1;
    while (end > 0) {
      if (isPalindrome(s, end)) {
        break;
      }
      end--;
    }

    string sub = s.substr(end + 1, s.size() - end - 1);
    reverse(sub.begin(), sub.end());

    return sub + s;
  }
};
// @lc code=end
