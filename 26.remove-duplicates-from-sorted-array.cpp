/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for(int n: nums) {
      if(!i || n > nums[i - 1]) {
        nums[i++] = n;
      }
    }
    return i;
  }
};
// @lc code=end

