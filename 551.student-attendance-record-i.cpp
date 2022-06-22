/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] Student Attendance Record I
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  bool checkRecord(string s) {
    int absentNum = 0;
    int consecutiveLateNum = 0;
    for(char c: s) {
      if(c == 'L') {
        consecutiveLateNum++;
      } else {
        consecutiveLateNum = 0;
        if(c == 'A') {
          absentNum++;
        }
      }
      if(absentNum >= 2 || consecutiveLateNum >= 3) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
