/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] Ransom Note
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    int dict[26]{};
    for (char c : magazine) {
      dict[c - 'a']++;
    }
    for (char c : ransomNote) {
      if (dict[c - 'a'] == 0)
        return false;
      dict[c - 'a']--;
    }
    return true;
  }
};
// @lc code=end
