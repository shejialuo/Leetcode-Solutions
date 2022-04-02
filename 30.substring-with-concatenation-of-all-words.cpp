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

// TODO: need to refactor

// @lc code=start
class Solution {
public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int stringLength = words[0].size();
    cout << stringLength << '\n';
    int wholeWindowSize = words.size() * stringLength;
    cout << wholeWindowSize << '\n';

    vector<int> ans {};

    unordered_map<string, int> hash;
    for(const auto& word: words) {
      hash[word]++;
    }

    int i = 0;
    while(i <= static_cast<int>(s.size()) - wholeWindowSize) {
      int j = i;
      while(j < i + wholeWindowSize) {
        string subStr = s.substr(j, stringLength);
        cout << subStr << '\n';
        if(hash[subStr]) {
          hash[subStr]--;
          j += stringLength;
        } else {
          break;
        }
        if(j == i + wholeWindowSize) {
          ans.push_back(i);
        }
      }
      i++;
      for(const auto& word: words) {
        hash[word] = 0;
      }
      for(const auto& word: words) {
        hash[word]++;
      }
    }
    return ans;
  }
};
// @lc code=end
