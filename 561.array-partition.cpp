/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] Array Partition
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int arrayPairSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());

    int ans = 0;
    for (int i = 0; i < nums.size(); i += 2) {
      ans += nums[i];
    }
    return ans;
  }
};
// @lc code=end
