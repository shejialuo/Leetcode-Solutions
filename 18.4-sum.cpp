/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 4Sum
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> ans{};
    sort(nums.begin(), nums.end());
    for (int j = 0; j < nums.size(); ++j) {
      if (nums[j] > target && (nums[j] >= 0 || target >= 0))
        break;

      if (j > 0 && nums[j] == nums[j - 1]) {
        continue;
      }

      for (int i = j + 1; i < nums.size(); ++i) {

        if (i > j + 1 && nums[i] == nums[i - 1]) {
          continue;
        }
        int start = i + 1, end = nums.size() - 1;
        while (start < end) {
          long sum = long(nums[i]) + long(nums[j]) + long(nums[start]) +
                     long(nums[end]);
          if (sum == target) {
            ans.push_back(
                vector<int>{nums[j], nums[i], nums[start], nums[end]});
            while (start < end && nums[start] == nums[start + 1]) {
              start++;
            }
            while (start < end && nums[end] == nums[end - 1]) {
              end--;
            }
            start++;
            end--;
          } else if (sum > target) {
            end--;
          } else {
            start++;
          }
        }
      }
    }
    return ans;
  }
};
// @lc code=end
