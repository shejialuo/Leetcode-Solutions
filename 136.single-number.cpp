/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] Single Number
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;
    for(int num: nums) {
      ans = ans ^ num;
    }
    return ans;
  }
};
// @lc code=end

