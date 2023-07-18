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
    int start = 0;
    int end = s.size() - 1;
    while (start < end) {
      swap(s[start++], s[end--]);
    }
  }
};
// @lc code=end
