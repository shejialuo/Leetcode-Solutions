/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] Decode String
 */

#include <string>
#include <cctype>
using namespace std;

// @lc code=start
class Solution {
private:
  string decodeStringHelper(const string& s, int& index) {
    string decode {};
    int times = 0;
    while(index < s.size()) {
      char c = s[index];
      index++;
      if(c == '[') {
        string result = decodeStringHelper(s, index);
        for(int j = 0; j < times; ++j) {
          decode.append(result);
        }
        times = 0;
      } else if(c == ']') {
        return decode;
      } else if(isdigit(c)) {
        times = (c - '0') + (times * 10);
      } else {
        decode.insert(decode.end(), c);
      }
    }
    return decode;
  }
public:
  string decodeString(string s) {
    int start = 0;
    return decodeStringHelper(s, start);
  }
};
// @lc code=end

