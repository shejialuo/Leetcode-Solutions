/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

/*
 * Pay attention to the corner case
 */

// @lc code=start
class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, char> table{{'(', ')'}, {'[', ']'}, {'{', '}'}};
    stack<char> st;
    for (const char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        st.push(c);
      } else {
        if (st.empty() || c != table[st.top()]) {
          return false;
        } else {
          st.pop();
        }
      }
    }
    return st.empty();
  }
};
// @lc code=end
