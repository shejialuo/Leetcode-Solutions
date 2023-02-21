/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  int lowerBound(vector<int> &nums, int target) {
    int start = 0, end = nums.size();
    while (start < end) {
      int mid = (start + end) / 2;
      if (nums[mid] < target) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    return start;
  }

public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int start = lowerBound(nums, target);
    int end = lowerBound(nums, target + 1);
    if (start < nums.size() && nums[start] == target)
      return vector<int>{start, end - 1};
    else
      return vector<int>{-1, -1};
  }
};
// @lc code=end
