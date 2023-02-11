/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] Set Mismatch
 */

#include <cmath>
#include <numeric>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief We should use in-place hash to quickly
   * solve this question. And pay attention to the
   * fact that x1 + ... + xi + ... + xj + ... + xn = actual
   * and x1 + ... + xi + ... + xi + ... + xn = should
   * we could use in-place hash to find xi, once we find xi
   * we can get xi - xj = should - actual, thus find xj.
   */
  vector<int> findErrorNums(vector<int> &nums) {

    int sumShould = (nums.size() + 1) * nums.size() / 2;
    int sumActual = 0;

    int occurTwice = -1;

    for (int i = 0; i < nums.size(); ++i) {
      sumActual += abs(nums[i]);
      if (nums[abs(nums[i]) - 1] < 0) {
        occurTwice = abs(nums[i]);
      } else {
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
      }
    }

    return {occurTwice, occurTwice - sumActual + sumShould};
  }
};
// @lc code=end
