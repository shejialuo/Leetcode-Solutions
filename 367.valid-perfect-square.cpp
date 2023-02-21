/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] Valid Perfect Square
 */

// @lc code=start
#include <cstdint>
class Solution {
public:
  bool isPerfectSquare(int num) {
    int start = 0, end = num;
    while (start <= end) {
      int mid = start + (end - start) / 2;
      long squareNum = (long)mid * mid;
      if (squareNum == num) {
        return true;
      } else if (squareNum < num) {
        start = mid + 1;
      } else {
        end = mid - 1;
      }
    }
    return false;
  }
};
// @lc code=end
