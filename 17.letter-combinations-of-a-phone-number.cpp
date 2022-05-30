/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
private:
  vector<string> result {};

  vector<string>letter {"abc", "def", "ghi", "jkl", "mno",
                        "pqrs", "tuv", "wxyz"};

  void helper(string& str, const string& digits, int i) {
    if(i == digits.size()) {
      if(!str.empty()) {
        result.push_back(str);
      }
    } else {
      int digit = digits[i] - '0';
      for (char c : letter[digit - 2]) {
        str.insert(str.end(), c);
        helper(str, digits, i + 1);
        str.erase(str.end() - 1, str.end());
      }
    }

  }
public:
  vector<string> letterCombinations(string digits) {
    string str {};
    helper(str, digits, 0);
    return result;
  }
};
// @lc code=end

