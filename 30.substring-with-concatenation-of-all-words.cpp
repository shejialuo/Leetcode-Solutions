/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

/*
  * For this problem, we should define the window,
  * the window size should be the words.size() *
  * word's length. And we just move the two pointer
  * one by one to solve this problem.
*/

// @lc code=start
class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int stringLength = words[0].size();
    int wholeWindowSize = words.size() * stringLength;

    vector<int> ans {};

    unordered_map<string, int> hash {};
    for(const auto& word: words) {
      hash[word]++;
    }

    for(int i = 0; i <= static_cast<int>(s.size()) - wholeWindowSize; ++i ) {
      unordered_map<string, int> window {};
      int j = i;
      while(j < i + wholeWindowSize) {
        string word = s.substr(j, stringLength);
        if(hash[word] != 0) {
          window[word]++;
          if(window[word] > hash[word]) break;
        } else {
          break;
        }
        j += stringLength;
        if(j == i + wholeWindowSize) {
          ans.push_back(i);
        }
      }
    }
    return ans;
  }
};
// @lc code=end
