/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] Minimum Swaps To Make Sequences Increasing
 */

#include <algorithm>
#include <limits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief This is the state dp problem. And we could easily
   * get the state dp.
   *
   * dp[i][0]: ith number doesn't swap's minimum swap.
   * dp[i][1]: ith number swap's minimum swap.
   *
   * However, it is hard to infer the state transition. We should
   * not consider about the swap operation itself, and we should
   * think what if the previous is swapped, because we have state
   * dp[i - 1][0] and dp[i - 1][1].
   */
  int minSwap(vector<int> &nums1, vector<int> &nums2) {
    vector<vector<int>> dp(nums1.size(), vector<int>(2, 0));

    dp[0][0] = 0;
    dp[0][1] = 1;

    for (int i = 1; i < nums1.size(); i++) {
      if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
        if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
          // In this situation, we could swap or not swap the `nums1[i]` and
          // `nums2[i]`.
          dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
          dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        } else {
          // If not, you may think we could not swap. However, there would
          // be situation that the i-1 operation has been swapped. So we should
          // not think question in this way, we should be consistent with
          // the operation with i-1 operation. If it swapped, we should swapped.
          // Else, we should not. This is the most difficult part.
          dp[i][0] = dp[i - 1][0];
          dp[i][1] = dp[i - 1][1] + 1;
        }
      } else {
        // If i-1 operation swap, we should not swap.
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + 1;
      }
    }

    return min(dp.back()[0], dp.back()[1]);
  }
};
// @lc code=end
