/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] Summary Ranges
 */

#include <vector>
#include <string>
using namespace std;

// TODO: need to refactor

// @lc code=start
class Solution {
public:
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ans{};
    string s{};
    int i = 0;
    if(nums.size() == 1) return vector<string> {to_string(nums[0])};
    for(; i < nums.size(); ++i) {
      if(i == nums.size() - 1) {
        if(nums[i - 1] + 1 != nums[i] || s.empty()) {
          ans.push_back(move(to_string(nums[i])));
        } else {
          s.append(to_string(nums[i]));
          ans.push_back(move(s));
        }
        break;
      }
      if(nums[i] + 1 != nums[i + 1]) {
        if(s.empty()) {
          ans.push_back(move(to_string(nums[i])));
        } else {
          s.append(to_string(nums[i]));
          ans.push_back(move(s));
          s = "";
        }
      } else {
        if(s.empty()) {
          s = to_string(nums[i]) + "->";
        }
      }
    }
    return ans;
  }
};
// @lc code=end

