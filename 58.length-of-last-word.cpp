/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  int lengthOfLastWord(string s) {
    int ans = 0;
    for(int i = 0; i < s.size();) {
      if(s[i] == ' ') {
        while(s[i] == ' ') i++;
        // Not the last word
        if(i != s.size()) {
          // Reset `ans`.
          ans = 0;
        }
      } else {
        ans++;
        i++;
      }
    }
    return ans;
  }
};
// @lc code=end

