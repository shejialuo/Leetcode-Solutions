/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] Plus One
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    vector<int> ans = digits;
    int C = 1;
    for(int i = ans.size() - 1; i >=0; i--) {
      ans[i] = (digits[i] + C) % 10;
      C = (digits[i] + C) / 10;
    }
    if(C != 0) {
      ans.insert(ans.begin(), C);
    }
    return ans;
  }

};
// @lc code=end

