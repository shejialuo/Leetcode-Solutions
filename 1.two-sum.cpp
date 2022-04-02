/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash {};
    for(int i = 0; i < nums.size(); ++i) {
      if(hash[target - nums[i]] != 0) {
        return vector<int>{i, hash[target-nums[i]] - 1};
      }
      hash[nums[i]] = i + 1;
    }
    return vector<int>{};
  }
};
// @lc code=end
