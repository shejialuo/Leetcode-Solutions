/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

#include <cmath>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> ans(nums.size(), 0);
    int i = nums.size() - 1;

    int left = 0, right = nums.size() - 1;

    while (left <= right) {
      if (abs(nums[left]) >= abs(nums[right])) {
        ans[i--] = nums[left] * nums[left];
        left++;
      } else {
        ans[i--] = nums[right] * nums[right];
        right--;
      }
    }
    return ans;
  }
};
// @lc code=end
