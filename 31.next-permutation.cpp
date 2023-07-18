/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] Next Permutation
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int j = nums.size() - 1;
    int i = j - 1;

    // 1. First find the first nums[i] < nums[j].
    while (i >= 0) {
      if (nums[i] < nums[j]) {
        break;
      }
      i--;
      j--;
    }

    // If not find, we need to reverse the whole
    // array
    if (i < 0) {
      reverse(nums.begin(), nums.end());
      return;
    }

    // From n - 1 to j, find the first element which
    // would be greater than nums[i], swap the nums[i],
    // and the current
    for (int k = nums.size() - 1; k >= j; k--) {
      if (nums[k] > nums[i]) {
        swap(nums[k], nums[i]);
        break;
      }
    }

    reverse(nums.begin() + j, nums.end());
  }
};
// @lc code=end
