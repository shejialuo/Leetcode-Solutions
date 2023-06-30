/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

#include <algorithm>
#include <limits>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   * @brief We could use unordered_set to think about this
   * question, if we find a value, we could get its value
   * from the begin. Well, whatever.
   *
   * And we inspect its left and right and erase the value
   * from the `unordered_set`. Thus, we would inspect every value
   * only once.
   *
   */
  int longestConsecutive(vector<int> &nums) {

    unordered_set<int> tables{};
    for (const int num : nums) {
      tables.insert(num);
    }

    int consecutive = 0;
    int num = 0;

    while (!tables.empty()) {
      int value = *tables.begin();
      tables.erase(value);

      num++;
      int left = value + 1;
      int right = value - 1;

      while (tables.count(left)) {
        num++;
        tables.erase(left);
        left++;
      }

      while (tables.count(right)) {
        num++;
        tables.erase(right);
        right--;
      }

      consecutive = max(consecutive, num);
      num = 0;
    }

    return consecutive;
  }
};
// @lc code=end
