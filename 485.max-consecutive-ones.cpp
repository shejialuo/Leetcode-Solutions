/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int consecutiveOnes = 0, maxConsecutiveOnes = 0;
    for (int num : nums) {
      if (num == 1) {
        consecutiveOnes++;
      } else {
        consecutiveOnes = 0;
      }
      if (consecutiveOnes > maxConsecutiveOnes) {
        maxConsecutiveOnes = consecutiveOnes;
      }
    }
    return maxConsecutiveOnes;
  }
};
// @lc code=end
