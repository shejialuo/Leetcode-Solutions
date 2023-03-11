/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

#include <functional>
#include <map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief subsequence is a classical question for dp.
   *
   */
  int lengthOfLIS(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);

    // Use map to maintain a ordered tree to
    // improve efficiency
    map<int, int, greater<>> table{};

    for (int i = 0; i < nums.size(); ++i) {
      for (auto &&[value, index] : table) {
        if (nums[i] > nums[index]) {
          dp[i] = value + 1;
          break;
        }
      }

      table[dp[i]] = i;
    }

    return table.begin()->first;
  }
};
// @lc code=end
