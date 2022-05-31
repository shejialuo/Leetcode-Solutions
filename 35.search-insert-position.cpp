/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int i = 0, j = nums.size(), mid = 0;
    while(i < j) {
      mid = (i + j) / 2;
      if(nums[mid] < target) {
        i = mid + 1;
      } else {
        j = mid;
      }
    }
    return i;
  }
};
// @lc code=end

