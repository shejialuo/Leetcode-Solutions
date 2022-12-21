/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * It is a easy question, just extract the description
   * to algorithm
   */
  int findPoisonedDuration(vector<int> &timeSeries, int duration) {
    int result = 0;
    for (size_t i = 0; i < timeSeries.size() - 1; ++i) {
      if (timeSeries[i + 1] - timeSeries[i] >= duration) {
        result += duration;
      } else {
        result += timeSeries[i + 1] - timeSeries[i];
      }
    }
    return result + duration;
  }
};
// @lc code=end
