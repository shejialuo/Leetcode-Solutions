/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] Find All Duplicates in an Array
 */

#include <vector>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans{};
    for(int i = 0; i < nums.size(); ++i) {
      int index = abs(nums[i]) - 1;
      nums[index] = -nums[index];
      if(nums[index] > 0) {
        ans.push_back(index + 1);
      }
    }
    // To restore the value
    for(int i = 0; i < nums.size(); ++i) {
      nums[i] = abs(nums[i]);
    }
    return ans;
  }
};
// @lc code=end

