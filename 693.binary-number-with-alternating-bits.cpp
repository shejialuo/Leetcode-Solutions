/*
 * @lc app=leetcode.cn id=693 lang=cpp
 *
 * [693] Binary Number with Alternating Bits
 */

// @lc code=start
class Solution {
public:
  bool hasAlternatingBits(int n) {
    while(n != 0) {
      if ((n & 0x01) == ((n & 0x02) >> 1)) {
        return false;
      }
      n >>= 1;
    }
    return true;
  }
};
// @lc code=end

