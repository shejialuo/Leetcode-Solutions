/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

#include <algorithm>
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
      reverse(nums.begin(), nums.end());
      return;
    }

    for (int k = nums.size() - 1; k >= j; k--) {
      if (nums[k] > nums[i]) {
        swap(nums[k], nums[i]);
        break;
      }
    }

    reverse(nums.begin() + j, nums.end());
  }

public:
  string getPermutation(int n, int k) {
    string ans{};
    for (int i = 1; i <= n; i++) {
      ans.push_back(i + '0');
    }
    for (int i = 0; i < k - 1; i++) {
      nextPermutation(ans);
    }
    return ans;
  }
};
// @lc code=end
