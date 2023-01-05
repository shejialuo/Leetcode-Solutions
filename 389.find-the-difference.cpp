/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] Find the Difference
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  char findTheDifference(string s, string t) {
    char ans{};
    for (size_t i = 0; i < s.size(); ++i) {
      ans ^= s[i] ^ t[i];
    }
    return ans ^ t.back();
  }
};
// @lc code=end
