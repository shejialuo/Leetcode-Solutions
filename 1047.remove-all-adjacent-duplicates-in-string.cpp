/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  string removeDuplicates(string s) {
    string ans;
    ans.push_back(s[0]);

    for (int i = 1; i < s.length(); i++) {

      if (s[i] == ans.back()) {
        ans.pop_back();
      } else {
        ans.push_back(s[i]);
      }
    }

    return ans;
  }
};
// @lc code=end
