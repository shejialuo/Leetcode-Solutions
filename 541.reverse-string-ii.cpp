/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] Reverse String II
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
private:
  void swapHelper(string &s, int start, int end) {
    while (start < end) {
      swap(s[start++], s[end--]);
    }
  }

public:
  string reverseStr(string s, int k) {
    int i = 0, length = s.size() - 2 * k;
    for (; i < length; i += 2 * k) {
      swapHelper(s, i, i + k - 1);
    }
    int remainLength = s.size() - i;
    if (remainLength < k) {
      swapHelper(s, i, s.size() - 1);
    } else {
      swapHelper(s, i, i + k - 1);
    }
    return s;
  }
};
// @lc code=end
