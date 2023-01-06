/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] Degree of an Array
 */

#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  struct Info {
    int frequency;
    int firstOccurrenceIndex;
    Info() = default;
    Info(int index) : frequency{1}, firstOccurrenceIndex{index} {}
  };

public:
  /**
   * @brief We do not need to use a window to solve this problem.
   * We first need to define a `Info` structure to record the
   * first time a digit occurs. We scan the whole array, when
   * the degree exceeds (in the frequency in the `Info`), we should
   * update the `shortestLength`, when it equals the current `maxDegree`,
   * we should check whether it is shorter.
   * This problem is not easy.
   */
  int findShortestSubArray(vector<int> &nums) {
    int shortestLength = numeric_limits<int>::max();
    int maxDegree = 0;
    unordered_map<int, Info> table{};
    int index = 0;
    while (index < nums.size()) {
      int val = nums[index];
      if (table.count(val)) {
        table[val].frequency++;
      } else {
        Info info{index};
        table[val] = std::move(info);
      }

      if (table[val].frequency == maxDegree) {
        shortestLength =
            min(shortestLength, index - table[val].firstOccurrenceIndex + 1);
        maxDegree = table[val].frequency;
      } else if (table[val].frequency > maxDegree) {
        shortestLength = index - table[val].firstOccurrenceIndex + 1;
        maxDegree = table[val].frequency;
      }
      index++;
    }
    return shortestLength;
  }
};
// @lc code=end
