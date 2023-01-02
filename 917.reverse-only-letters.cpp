/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 */

#include <cctype>
#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  string reverseOnlyLetters(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
      while (j >= 0 && !isalpha(s[j]))
        j--;
      while (i < s.size() && !isalpha(s[i]))
        i++;
      if (i < j) {
        swap(s[i], s[j]);
      }
      i++;
      j--;
    }
    return s;
  }
};
// @lc code=end
