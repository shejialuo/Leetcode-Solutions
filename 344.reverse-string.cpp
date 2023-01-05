/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] Reverse String
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  void reverseString(vector<char> &s) {
    int pre = 0;
    int end = s.size() - 1;
    while (pre < end) {
      swap(s[pre++], s[end--]);
    }
  }
};
// @lc code=end
