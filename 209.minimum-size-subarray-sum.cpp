/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

#include <vector>
#include <limits>
using namespace std;

/*
  * For this question, it is easy to think to use sliding
  * window to solve this question.
*/

// @lc code=start
class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int length = numeric_limits<int>::max();
    int start = 0, end = 0, sum = 0;
    while(end < nums.size()) {
      sum += nums[end++];
      while(sum >= target) {
        length = min(end - start, length);
        sum -= nums[start++];
      }
    }
    return length == numeric_limits<int>::max() ? 0 : length;
  }
};
// @lc code=end

