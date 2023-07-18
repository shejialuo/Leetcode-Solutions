/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <limits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int maxArea(vector<int> &height) {
    int start = 0, end = height.size() - 1;
    int ans = numeric_limits<int>::min();
    while (start < end) {
      ans = max(min(height[start], height[end]) * (end - start), ans);
      if (height[start] < height[end]) {
        start++;
      } else {
        end--;
      }
    }
    return ans;
  }
};
// @lc code=end
