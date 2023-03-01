/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  /**
   * @brief It is easy to think about using two pointers
   *
   */
  vector<int> twoSumTwoPointer(vector<int> &numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while (i < j) {
      if (numbers[i] + numbers[j] == target) {
        return {i + 1, j + 1};
      } else if (numbers[i] + numbers[j] > target) {
        j--;
      } else {
        i++;
      }
    }
    return {-1, -1};
  }

public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    return twoSumTwoPointer(numbers, target);
  }
};
// @lc code=end
