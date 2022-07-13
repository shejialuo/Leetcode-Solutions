/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <string>
#include <unordered_map>
using namespace std;

/*
  * This problem is solved by the sliding window, the idea is
  * to maintain two pointer `front` and `end` and an associative
  * array `isVisited`. When `s[end]` is in the `isVisited`, we
  * should move the `front` pointer to the first occurence of
  * the `[send]`. So actually, we maintain a loop variant that
  * is there is no repeating characters in the interval of
  * [front + 1, end], so the length is `end - front`. And don't
  * forget about the corner case, we need to recompute the max
  * length at the end of the program.
*/

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
