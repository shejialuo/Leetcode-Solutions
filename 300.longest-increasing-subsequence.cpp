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
private:
  int lengthOfLISTwoLoop(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[j] + 1, dp[i]);
        }
      }
      result = max(result, dp[i]);
    }
    return result;
  }

  int lengthOfLISWithMap(vector<int> &nums) {
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

public:
  /**
   * @brief subsequence is a classical question for dp.
   *
   */
  int lengthOfLIS(vector<int> &nums) { return lengthOfLISWithMap(nums); }
};
// @lc code=end
