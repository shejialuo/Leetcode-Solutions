/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 4Sum II
 */

#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief We could store the sum of the nums1 and nums2.
   * The idea is just like the 2-sum.
   *
   */
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    std::unordered_map<int, int> table{};

    for (int num1 : nums1) {
      for (int num2 : nums2) {
        table[num1 + num2]++;
      }
    }

    int ans = 0;
    for (int num3 : nums3) {
      for (int num4 : nums4) {
        if (table[0 - num3 - num4]) {
          ans += table[0 - num3 - num4];
        }
      }
    }
    return ans;
  }
};
// @lc code=end
