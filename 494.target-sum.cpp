/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] Target Sum
 */

// TODO: Add dynamic programming solution

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  int ans = 0;
  void helper(vector<int>& nums, int i, int sum, int target) {
    if(i == nums.size()) {
      if(sum == target) {
        ans++;
      }
    } else {
      helper(nums, i + 1, sum + nums[i], target);
      helper(nums, i + 1, sum - nums[i], target);
    }
  }
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    helper(nums, 0, 0, target);
    return ans;
  }
};
// @lc code=end

