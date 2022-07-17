/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

#include <vector>
#include <iostream>
using namespace std;

/*
  * For window size problem, it is important for us to keep
  * the loop invariant. In this problem the window contains
  * the k zero numbers. When it contains more, we should move
  * the start pointer to get the next window contains the k
  * zero numbers.
*/

// @lc code=start
class Solution {
public:
  static int longestOnes(vector<int>& nums, int k) {
    int ans = 0, zeroNumInWindow = 0;
    int start = 0, end = 0;
    while(end < nums.size()) {
      if(nums[end] == 0) {
        zeroNumInWindow++;
      }
      if(zeroNumInWindow > k) {
        ans = max(ans, end - start);
        while(zeroNumInWindow != k) {
          if(nums[start] == 0) {
            zeroNumInWindow--;
          }
        start++;
        }
      }
      end++;
    }
    // Don't forget the corner case
    return max(ans, end - start);
  }
};
// @lc code=end

