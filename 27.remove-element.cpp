/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] Remove Element
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int pointerNotEqual = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[pointerNotEqual++] = nums[i];
      }
    }
    return pointerNotEqual;
  }
};
// @lc code=end
