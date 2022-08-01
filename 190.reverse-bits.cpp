/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

#include <cstdint>

/*
  * The key idea of the optimization is to look up a 4 bit chuck and find
  * out what the reverse is. For example, reverse of 0001 is 1000
  * (in decimal reverse of 1 is 8).
*/

// @lc code=start
class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    char tb[16] = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15};
    uint32_t ans = 0;
    const uint32_t msk = 0xF;
    for(int i = 0; i < 8; i++) {
      ans <<= 4;
      ans |= tb[msk & n];
      n >>= 4;
    }
    return ans;
  }
};
// @lc code=end

