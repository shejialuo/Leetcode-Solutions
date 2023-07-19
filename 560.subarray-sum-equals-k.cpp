/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> prefix{};
    prefix[0] = 1;

    int sum = 0, ans = 0;
    for (int num : nums) {
      sum += num;
      ans += prefix[sum - k];
      prefix[sum]++;
    }
    return ans;
  }
};
// @lc code=end
