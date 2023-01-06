/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief It is an easy problem.
   */
  int pivotIndex(vector<int> &nums) {
    int sum = 0;
    for (int num : nums) {
      sum += num;
    }
    int leftSum = 0, rightSum = sum;
    for (int index = 0; index < nums.size(); index++) {
      rightSum -= nums[index];
      if (leftSum == rightSum) {
        return index;
      }
      leftSum += nums[index];
    }
    return -1;
  }
};
// @lc code=end
