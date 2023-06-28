/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] Largest Number
 */

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  string largestNumber(vector<int> &nums) {
    vector<string> strs{};
    for (int num : nums) {
      strs.push_back(to_string(num));
    }

    sort(strs.begin(), strs.end(),
         [](const string &s1, const string &s2) { return s1 + s2 > s2 + s1; });

    string ans{};
    for (const auto &str : strs) {
      ans += str;
    }

    return ans[0] == '0' ? "0" : ans;
  }
};
// @lc code=end
