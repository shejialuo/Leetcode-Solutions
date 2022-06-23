/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  int countSegments(string s) {
    bool isNewWord = false;
    int segmentNumber= 0;
    for(char c : s) {
      if(c == ' ') {
        if(isNewWord) {
          segmentNumber++;
          isNewWord = false;
        }
      } else {
        isNewWord = true;
      }
    }
    if(isNewWord) segmentNumber++;
    return segmentNumber;
  }
};
// @lc code=end

