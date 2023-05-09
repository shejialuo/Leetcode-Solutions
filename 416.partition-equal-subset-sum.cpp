/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

#include <numeric>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief We should convert this problem to 0/1 packing problem
   * The problem is let us to split the array. So we have two sets
   * A and B. And the choice is to put it in the A or put it in the B.
   * And the target is the sum(array) / 2.
   *
   */
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.cbegin(), nums.cend(), 0);
    if (sum % 2 != 0) {
      return false;
    }

    int target = sum / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int i = 0; i < nums.size(); i++) {
      for (int j = target; j >= nums[i]; j--) {
        if (dp[j - nums[i]]) {
          dp[j] = true;
        }
      }
    }
    return dp.back();
  }
};
// @lc code=end
