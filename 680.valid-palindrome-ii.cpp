/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
private:
  bool validPalindromeHelper(string &s, int i, int j) {
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
    int i = 0, j = s.size() - 1;
    while (i < j) {
      if (s[i] != s[j]) {
        return validPalindromeHelper(s, i + 1, j) ||
               validPalindromeHelper(s, i, j - 1);
      }
      i++;
      j--;
    }
    return true;
  }
};
// @lc code=end
