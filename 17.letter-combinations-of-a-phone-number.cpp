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
  vector<string> letter{"abc", "def",  "ghi", "jkl",
                        "mno", "pqrs", "tuv", "wxyz"};

  void helper(vector<string> &result, string &str, const string &digits,
              int i) {
    if (i == str.size()) {
      result.push_back(str);
      return;
    }

    for (char c : letter[digits[i] - '2']) {
      str[i] = c;
      helper(result, str, digits, i + 1);
    }
  }

public:
  vector<string> letterCombinations(string digits) {

    vector<string> result{};
    if (digits.empty()) {
      return result;
    }
    string str{};
    str.resize(digits.size());
    helper(result, str, digits, 0);
    return result;
  }
};
// @lc code=end
