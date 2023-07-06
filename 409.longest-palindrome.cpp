/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] Longest Palindrome
 */

#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
  int longestPalindrome(string s) {
    unordered_map<char, int> frequency{};
    for (char c : s) {
      frequency[c]++;
    }

    int ans = 0;
    bool once = true;
    for (auto &&[c, fre] : frequency) {
      ans += (fre / 2) * 2;
      if (fre % 2 != 0 && once) {
        ans++;
        once = false;
      }
    }
    return ans;
  }
};
// @lc code=end
