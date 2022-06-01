/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
  string reverseVowels(string s) {
    unordered_set<char> hash {'a', 'e', 'i', 'o', 'u',
                              'A', 'E', 'I', 'O', 'U'};
    int i = 0, j = s.size() - 1;
    while(i < j) {
      while(i < j && hash.count(s[i]) == 0) {
        i++;
      }
      while(i < j && hash.count(s[j]) == 0) {
        j--;
      }
      if(i < j) {
        swap(s[i], s[j]);
      }
      i++; j--;
    }
    return s;
  }
};
// @lc code=end

