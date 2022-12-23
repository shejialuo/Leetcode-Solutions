/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

#include <string>
#include <vector>
using namespace std;

/*
 * The basic backtracing problem. However, in order to improve the
 * performance, we should NOT do any dynamic memory operation instead
 * we should use STATIC string array.
 */

// @lc code=start
class Solution {
private:
  vector<string> result{};

  vector<string> letter{"abc", "def",  "ghi", "jkl",
                        "mno", "pqrs", "tuv", "wxyz"};

  void helper(string &str, const string &digits, int i) {
    if (i == digits.size()) {
      result.push_back(str);
    } else {
      int digit = digits[i] - '0';
      for (char c : letter[digit - 2]) {
        str[i] = c;
        helper(str, digits, i + 1);
      }
    }
  }

public:
  vector<string> letterCombinations(string digits) {
    string str{};
    str.resize(digits.size());
    if (digits.empty())
      return result;
    helper(str, digits, 0);
    return result;
  }
};
// @lc code=end
