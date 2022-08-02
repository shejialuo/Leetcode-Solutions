/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] House Robber
 */

#include <vector>
using namespace std;

/*
  * It is easy to write the brute-force solution. First,
  * if we are at the neighborhood of the robbed we just
  * get next value. If not, we have two choices:
  *
  * 1. Rob it
  * 2. Don't rob it.
  *
  * However, we need to use dynamic programming to solve
  * this problem. From the brute-force answer, we can
  * simply get the idea.
*/

// @lc code=start
class Solution {
private:
  int robHelper(vector<int>& nums, int index, int recent) {
    if(index < nums.size()) {
      if(index == recent + 1) {
        return robHelper(nums, index + 1, recent);
      } else {
        return max(robHelper(nums, index + 1, index) + nums[index], robHelper(nums, index + 1, recent));
      }
    }
    return 0;
  }
public:
  int rob(vector<int>& nums) {
    // Brute Force
    // return robHelper(nums, 0, -2);

    if(nums.size() == 1) return nums[0];
    if(nums.size() == 2) return max(nums[0], nums[1]);
    int dp[nums.size()];
    dp[0] = nums[0];
    dp[1] = max(dp[0], nums[1]);
    for(int i = 2; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[nums.size() - 1];
  }
};
// @lc code=end

