/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] Contains Duplicate II
 */

#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); ++i) {
      if (hash[nums[i]] != 0) {
        if (abs(i - (hash[nums[i]] - 1)) <= k) {
          return true;
        }
      }
      hash[nums[i]] = i + 1;
    }
    return false;
  }
};
// @lc code=end
