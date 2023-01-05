/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  bool containsDuplicate(vector<int> &nums) {
    unordered_set<int> hash{};
    for (int i = 0; i < nums.size(); ++i) {
      if (hash.count(nums[i]) != 0) {
        return true;
      }
      hash.insert(nums[i]);
    }
    return false;
  }
};
// @lc code=end
