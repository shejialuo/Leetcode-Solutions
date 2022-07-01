/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

#include <cstdint>

// @lc code=start
class Solution {
public:
  int hammingWeight(uint32_t n) {
    int ans = 0;
    while(n) {
      ans += n & 0x01;
      n >>= 1;
    }
    return ans;
  }
};
// @lc code=end

