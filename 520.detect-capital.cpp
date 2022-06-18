/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] Detect Capital
 */

#include <string>
#include <cctype>
using namespace std;

// @lc code=start
class Solution {
public:
  bool detectCapitalUse(string word) {
    if(word.size() == 1) return true;
    bool isFirstUpper = false;
    bool isRemainAllUpper = true;
    bool isRemainAllLower = true;
    if(isupper(word[0])) {
      isFirstUpper = true;
    }
    for(int i = 1; i < word.size(); ++i) {
      if(isupper(word[i])) {
        isRemainAllUpper = isRemainAllUpper && true;
        isRemainAllLower = false;
      } else {
        isRemainAllUpper = false;
        isRemainAllLower = isRemainAllLower && true;
      }
    }
    return (isFirstUpper && (isRemainAllLower || isRemainAllUpper))
           || (!isFirstUpper) && isRemainAllLower;

  }
};
// @lc code=end

