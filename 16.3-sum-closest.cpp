/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

#include <algorithm>
#include <cstdlib>
#include <limits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int ans = numeric_limits<int>::max();

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {

      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int start = i + 1, end = nums.size() - 1;
      while (start < end) {
        int sum = nums[i] + nums[start] + nums[end];
        if (sum == target) {
          return target;
        } else if (sum > target) {
          end--;
        } else {
          start++;
        }

        if (ans == numeric_limits<int>::max() ||
            abs(sum - target) < abs(ans - target)) {
          ans = sum;
        }
      }
    }

    return ans;
  }
};
// @lc code=end
