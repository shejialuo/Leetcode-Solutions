/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] Next Greater Element III
 */

#include <algorithm>
#include <limits>
#include <string>
using namespace std;

// @lc code=start
class Solution {
private:
  void nextPermutation(string &nums) {
    int j = nums.size() - 1, i = j - 1;
    while (i >= 0) {
      if (nums[i] < nums[j]) {
        break;
      }
      i--;
      j--;
    }

    if (i < 0) {
      return;
    }

    for (int k = nums.size() - 1; k >= 0; k--) {
      if (nums[k] > nums[i]) {
        swap(nums[k], nums[i]);
        break;
      }
    }

    reverse(nums.begin() + j, nums.end());
  }

public:
  int nextGreaterElement(int n) {
    string nums = to_string(n);
    nextPermutation(nums);
    long ans = stol(nums);

    if (ans > numeric_limits<int>::max() || ans == n) {
      return -1;
    }

    return ans;
  }
};
// @lc code=end
