/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

#include <string>
using namespace std;

/*
  * It's important to figure out the change of state
*/

// @lc code=start
class Solution {
public:
  int lengthOfLastWord(string s) {
    int ans = 0;
    bool newWord = true;
    for(char c : s) {
      if(c == ' ') {
        newWord = true;
      } else {
        if(newWord) {
          ans = 0;
          newWord = false;
        }
        ans++;
      }
    }
    return ans;
  }
};
// @lc code=end

