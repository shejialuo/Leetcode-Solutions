/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  bool isIsomorphic(string s, string t) {
    char mapS[128] = { 0 };
    char mapT[128] = { 0 };
    for(int i = 0; i < s.size(); ++i){
      if(mapS[s[i]]!=mapT[t[i]]) return false;
        mapS[s[i]] = i+1;
        mapT[t[i]] = i+1;
      }
    return true;
  }
};
// @lc code=end

