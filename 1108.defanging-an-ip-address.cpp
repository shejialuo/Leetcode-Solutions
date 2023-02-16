/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  string defangIPaddr(string address) {
    string ans{};
    ans.resize(address.size() + 6);

    int i = 0;

    for (char c : address) {
      if (c != '.') {
        ans[i++] = c;
      } else {
        ans[i++] = '[';
        ans[i++] = '.';
        ans[i++] = ']';
      }
    }
    return ans;
  }
};
// @lc code=end
