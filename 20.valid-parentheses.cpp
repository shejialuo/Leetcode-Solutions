/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
  bool isValid(string s) {
    unordered_map<char, char> hash {
      {'(', ')'}, {'[', ']'}, {'{', '}'}
    };
    stack<char> st;
    for(const char c: s) {
      if(c == '(' || c == '[' || c == '{') {
        st.push(c);
      } else {
        if(st.empty()) {
          return false;
        } else if(c == hash[st.top()]) {
          st.pop();
        } else {
          return false;
        }
      }
    }
    if(st.empty()) {
      return true;
    } else {
      return false;
    }
  }
};
// @lc code=end

