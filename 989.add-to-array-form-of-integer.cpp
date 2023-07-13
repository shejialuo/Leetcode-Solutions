/*
 * @lc app=leetcode.cn id=989 lang=cpp
 *
 * [989] Add to Array-Form of Integer
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> addToArrayForm(vector<int> &num, int k) {
    vector<int> ans{};

    int C = 0;
    int index = num.size() - 1;
    while (index >= 0 || k > 0) {
      int val = index >= 0 ? num[index] : 0;
      int sum = (val + k % 10 + C) % 10;
      C = (val + k % 10 + C) / 10;
      ans.push_back(sum);
      k /= 10;
      index--;
    }

    if (C != 0) {
      ans.push_back(C);
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
