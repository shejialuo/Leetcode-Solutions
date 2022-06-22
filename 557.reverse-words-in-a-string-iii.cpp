/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
private:
  void reverse(string &s, int start, int end) {
    while(start < end) {
      swap(s[start++], s[end--]);
    }
  }
public:
  string reverseWords(string s) {
    int i = 0, j = 0;
    while(i < s.size()) {
      while(s[j] != ' ' && j < s.size()) j++;
      reverse(s, i, j - 1);
      j++;
      i = j;
    }
    return s;
  }
};
// @lc code=end

