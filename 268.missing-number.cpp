/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] Missing Number
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int ans = nums.size();
    for(int i = 0; i < nums.size(); ++i) {
      ans ^= nums[i] ^ i;
    }
    return ans;
  }
};
// @lc code=end

