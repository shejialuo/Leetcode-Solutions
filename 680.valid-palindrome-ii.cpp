/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

#include <string>
using namespace std;

// TODO: now the solution uses burte-force, need to refactor

// @lc code=start
class Solution {
private:
  bool validPalindromeHelper(string &s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (s[i] != s[j]) {
        return false;
      }
      i++;
      j--;
    }
    return true;
  }

public:
  bool validPalindrome(string s) {
    bool ans = validPalindromeHelper(s);
    for (int i = 0; i < s.size(); ++i) {
      string s_ = s;
      s_.erase(i, 1);
      ans = ans || validPalindromeHelper(s_);
    }
    return ans;
  }
};
// @lc code=end
