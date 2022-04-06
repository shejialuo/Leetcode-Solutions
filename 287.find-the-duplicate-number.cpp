/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// TODO: Write more solutions.

#include <vector>
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:

  /*
    * Since the numbers are [1:N], so we use the
    * array indices for s visited state of each
    * number, only the duplicate will be visit

    * In-place Hash
  */
  int indexSolution(vector<int>& nums) {
    for(int i = 0; i < nums.size(); ++i) {
      int index = abs(nums[i]) - 1;
      nums[index] *= -1;
      if(nums[index] > 0) {
        return abs(nums[i]);
      }
    }
    return -1;
  }

  /*
    * Floyd circle detection
  */
  int folydCircleSolution(vector<int>& nums) {

  }

  int findDuplicate(vector<int>& nums) {
    return indexSolution(nums);
  }
};
// @lc code=end

