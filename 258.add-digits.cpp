/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
  int addDigits(int num) {
    while (num >= 10) {
      int n = num;
      num = 0;
      while (n) {
        num += n % 10;
        n /= 10;
      }
    }
    return num;
  }
};
// @lc code=end
