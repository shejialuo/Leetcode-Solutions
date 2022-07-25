/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
  int romanToInt(string s) {
    unordered_map<char, int> table{
      {'I', 1}, {'V', 5}, {'X', 10},
      {'L', 50}, {'C', 100}, {'D', 500},
      {'M', 1000}
    };
    int ans = 0;
    for(int i = 0; i < s.size() - 1; ++i) {
      if(table[s[i]] < table[s[i + 1]]) ans -= table[s[i]];
      else ans += table[s[i]];
    }
    return ans + table[s.back()];
  }
};
// @lc code=end

