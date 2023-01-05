/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] Word Pattern
 */

#include <sstream>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
  bool wordPattern(string pattern, string s) {
    istringstream ss{s};
    unordered_map<char, int> p2i{};
    unordered_map<string, int> w2i{};
    int i = 0, n = pattern.size();
    for (string word; ss >> word; ++i) {
      if (i == n || p2i[pattern[i]] != w2i[word])
        return false;
      p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
  }
};
// @lc code=end
