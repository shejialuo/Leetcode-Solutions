/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

#include <limits>
#include <cstdint>
using namespace std;

/*
  * In this problem, we should consider about the overflow,
  * We use cpp standard library to determine the min and max.
*/

// @lc code=start
class Solution {
public:
  int reverse(int x) {
    int32_t y = 0;
    int32_t signedMin = numeric_limits<int32_t>::min();
    int32_t signedMax = numeric_limits<int32_t>::max();
    while(x) {
      if(y < signedMin / 10 || y > signedMax / 10 ) return 0;
        y = y * 10 + x % 10;
        x /= 10;
      }
    return y;
  }
};
// @lc code=end

