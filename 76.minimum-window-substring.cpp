/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

#include <string>
#include <limits>
#include <unordered_map>
using namespace std;

/*
  * In order to keep the number of char in string `t`, we need to
  * maintain two hash tables. Now we should define the window to
  * be the substring of string `s` CONTAINS the string `t`, which
  * means every character in t (including duplicates). So the interval
  * [start, end) is a window we found now. In order to track whether
  * we hit the window, I use `num` to keep the state. When `num==t.size()`,
  * we have hit the window, but the window may contain some duplicate
  * characters which makes the window not minimal, so we should move
  * the `start` pointer to get the minimal.
*/

// @lc code=start
class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> hash {};
    unordered_map<char, int> window {};
    for(char c : t) {
      hash[c]++;
    }
    int start = 0, end = 0, num = 0;
    int ansStartIndex = 0, ansEndIndex = 0;
    int minLength = numeric_limits<int>::max();
    while(end < s.size()) {

      if(hash.find(s[end]) != hash.cend()) {
        window[s[end]]++;
        if(window[s[end]] <= hash[s[end]]) num++;
      }
      end++;
      while(num == t.size()) {
        while(window[s[start]] == 0) start++;
        if(window[s[start]] <= hash[s[start]]) {
          num--;
        }
        window[s[start]]--;
        if(end - start < minLength) {
          minLength = end - start;
          ansStartIndex = start;
          ansEndIndex = end;
        }
        start++;
      }
    }
    return s.substr(ansStartIndex, ansEndIndex - ansStartIndex);
  }
};
// @lc code=end

