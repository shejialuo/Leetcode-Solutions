/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {

    int longestLength = 0;

    unordered_map<char, int> visitedElement{};

    int front = 0, end = 0;
    while(end < s.size()) {
      if(!visitedElement[s[end]]) {
        visitedElement[s[end++]] = end + 1;
      } else {
        longestLength = max(end - front, longestLength);
        while(front < visitedElement[s[end]]) {
          visitedElement[s[front++]] = 0;
        }
      }
    }

    longestLength = max(end - front, longestLength);

    return longestLength;
  }
};
// @lc code=end
