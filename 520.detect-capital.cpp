/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] Detect Capital
 */

#include <cctype>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  /**
   *
   * @param word the word
   * @return true All letters in this word are capitals
   *              All letters in this word are not capitals
   *              Only the first letter in this word is capital
   * @return false
   */
  bool detectCapitalUse(string word) {
    if (word.size() >= 2 && islower(word[0]) && isupper(word[1])) {
      return false;
    }

    // A wonderful abstraction.
    for (size_t i = 2; i < word.size(); ++i) {
      if (islower(word[i]) ^ islower(word[1])) {
        return false;
      }
    }

    return true;
  }
};
// @lc code=end
