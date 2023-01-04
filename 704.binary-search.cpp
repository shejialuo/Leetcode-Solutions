/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] Binary Search
 */

#include <vector>
using namespace std;

/*
 * For binary search, there are two kinds of methods:
 *   + To keep the interval as [left, right]
 *   + To keep the interval as [left, right)
 * They are all simple, but I prefer the second method
 */

// @lc code=start
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int start = 0, end = nums.size();
    while (start < end) {
      int mid = (start + end) / 2;
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] > target) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    return -1;
  }
};
// @lc code=end
