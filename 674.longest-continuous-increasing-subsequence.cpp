/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] Longest Continuous Increasing Subsequence
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int findLengthOfLCIS(vector<int> &nums) {
    int count = 1;
    int result = 1;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] > nums[i - 1]) {
        count++;
      } else {
        count = 1;
      }
      result = max(count, result);
    }
    return result;
  }
};
// @lc code=end
