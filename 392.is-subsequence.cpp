/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

#include <iostream>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  bool isSubsequence(string s, string t) {
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
};
// @lc code=end
