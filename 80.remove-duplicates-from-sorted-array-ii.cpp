/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

#include <limits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    int pointToWrite = 0, equalNum = 0;
    int preVisited = numeric_limits<int>::min();
    for (auto num : nums) {
      if (num == preVisited) {
        equalNum++;
      } else {
        equalNum = 1;
      }
      preVisited = num;
      if (equalNum <= 2) {
        nums[pointToWrite++] = num;
      }
    }
    return pointToWrite;
  }
};
// @lc code=end
