/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

#include <string>
#include <cctype>
using namespace std;

// @lc code=start
class Solution {
public:
  bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while(i < j) {
      while(j >= 0 && !isalnum(s[j])) j--;
      while(i < s.size() && !isalnum(s[i])) i++;
      if(i < j) {
        if(tolower(s[i]) != tolower(s[j])) {
          return false;
        }
      }
      i++; j--;
    }
    return true;
  }
};
// @lc code=end

