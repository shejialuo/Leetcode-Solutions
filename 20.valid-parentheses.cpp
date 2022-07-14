/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <string>
#include <stack>
#include <unordered_map>
using namespace std;

/*
  * Pay attention to the corner case
*/

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
        if(st.empty() || c != hash[st.top()]) {
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

