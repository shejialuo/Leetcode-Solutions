/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] To Lower Case
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  string toLowerCase(string s) {
    for(int i = 0; i < s.size(); ++i) {
      if('A' <= s[i] && s[i] <= 'Z') {
        s[i] += 'a' - 'A';
      }
    }
    return s;
  }
};
// @lc code=end

