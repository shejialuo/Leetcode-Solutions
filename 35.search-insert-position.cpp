/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

#include <vector>
using namespace std;

/*
 * Binary Search Application
 */

// @lc code=start
class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int start = 0, end = nums.size(), mid = 0;
    while (start < end) {
      mid = (start + end) / 2;
      if (nums[mid] < target) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    return start;
  }
};
// @lc code=end
