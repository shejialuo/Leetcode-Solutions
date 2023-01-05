/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length())
      return false;
    unordered_map<char, int> hash{};
    for (char c : s)
      hash[c]++;
    for (char c : t)
      hash[c]--;
    for (char c : s) {
      if (hash[c] != 0)
        return false;
    }
    return true;
  }
};
// @lc code=end
